// Copyright Epic Games, Inc. All Rights Reserved.

#include "AssetNamingPrefix.h"
#include "AssetNamingPrefixSettings.h"
#include "AssetToolsModule.h"
#include "ContentBrowserModule.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Engine/Engine.h"
#include "Misc/ScopedSlowTask.h"
#include "HAL/PlatformTime.h"
#include "TickableEditorObject.h"
#include "Misc/CoreDelegates.h"
#include "Containers/Queue.h"
#include "Engine/World.h"
#include "Editor.h"
#include "Misc/MessageDialog.h"
#include "GenericPlatform/GenericPlatformProcess.h"
#include "Misc/ScopedSlowTask.h"
#include "Logging/LogMacros.h"
#include "ISettingsModule.h"

#define LOCTEXT_NAMESPACE "FAssetNamingPrefixModule"

DEFINE_LOG_CATEGORY_STATIC(LogAssetNaming, Log, All);

void FAssetNamingPrefixModule::StartupModule()
{
	// Register Project Settings panel
	if (ISettingsModule* Settings = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		Settings->RegisterSettings(
		  "Project", "Plugins", "Asset Naming Prefix",
		  LOCTEXT("SettingsName", "Asset Naming Prefix"),
		  LOCTEXT("SettingsDesc", "Configure prefixes for new assets."),
		  GetMutableDefault<UAssetNamingPrefixSettings>()
		);
	}
	
	// Wait until the registry has scanned all existing assets
	FAssetRegistryModule& ARM = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	ARM.Get().OnFilesLoaded().AddRaw(this, &FAssetNamingPrefixModule::HandleRegistryFilesLoaded);

	// Register for asset-view (right-click on assets)
	FContentBrowserModule& CBModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");

	auto& AssetExtenders = CBModule.GetAllAssetViewContextMenuExtenders();
	AssetViewExtenderIndex = AssetExtenders.Add(
	  FContentBrowserMenuExtender_SelectedAssets::CreateRaw(this, &FAssetNamingPrefixModule::OnExtendAssetViewContextMenu)
	);

	auto& PathExtenders = CBModule.GetAllPathViewContextMenuExtenders();
	PathViewExtenderIndex = PathExtenders.Add(
	  FContentBrowserMenuExtender_SelectedPaths::CreateRaw(this, &FAssetNamingPrefixModule::OnExtendPathViewContextMenu)
	);
}


void FAssetNamingPrefixModule::ShutdownModule()
{
	// Unregister Project Settings panel
	if (ISettingsModule* SettingsMod = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsMod->UnregisterSettings(TEXT("Project"), TEXT("Plugins"), TEXT("Asset Naming Prefix"));
	}

	// Unhook registry listeners
	if (FModuleManager::Get().IsModuleLoaded("AssetRegistry"))
	{
		FAssetRegistryModule& ARM = FModuleManager::GetModuleChecked<FAssetRegistryModule>("AssetRegistry");
		ARM.Get().OnFilesLoaded().RemoveAll(this);
		ARM.Get().OnAssetAdded().RemoveAll(this);
	}

	// Remove the ticker
	if (TickHandle.IsValid())
	{
		FTSTicker::GetCoreTicker().RemoveTicker(TickHandle);
		TickHandle.Reset();
	}
	
	if (FModuleManager::Get().IsModuleLoaded("ContentBrowser"))
	{
		auto& CBModule = FModuleManager::GetModuleChecked<FContentBrowserModule>("ContentBrowser");

		auto& AssetExtenders = CBModule.GetAllAssetViewContextMenuExtenders();
		if (AssetViewExtenderIndex != INDEX_NONE && AssetViewExtenderIndex < AssetExtenders.Num())
		{
			AssetExtenders.RemoveAt(AssetViewExtenderIndex);
		}

		auto& PathExtenders = CBModule.GetAllPathViewContextMenuExtenders();
		if (PathViewExtenderIndex != INDEX_NONE && PathViewExtenderIndex < PathExtenders.Num())
		{
			PathExtenders.RemoveAt(PathViewExtenderIndex);
		}
	}
}

void FAssetNamingPrefixModule::OnAssetRegistryAssetAdded(const FAssetData& AssetData)
{
	const auto* Settings = GetDefault<UAssetNamingPrefixSettings>();
	if (!Settings || !Settings->bEnableAutoPrefix)
	{
		return;
	}

	// If we're allowing all paths, just enqueue.
	if (Settings->bAllowAllPaths)
	{
		PendingAssets.Enqueue(AssetData);
		return;
	}

	// Otherwise only enqueue if PackagePath matches one of the AllowedPaths
	const FString Pkg = AssetData.PackagePath.ToString();
	for (const FDirectoryPath& Dir : Settings->AllowedPaths)
	{
		if (Pkg.StartsWith(Dir.Path))
		{
			PendingAssets.Enqueue(AssetData);
			break;
		}
	}
}

bool FAssetNamingPrefixModule::TickProcessPending(float DeltaTime)
{
	// Get settings from plugin 
	const auto* Settings = GetDefault<UAssetNamingPrefixSettings>();
    if (!IsValid(Settings) || !Settings->bEnableAutoPrefix)
    {
        return true;  // we use to stop ticking but we want everything to update live 
    }

    // Load the table
    UDataTable* Table = Settings->PrefixTable.LoadSynchronous();
    if (!IsValid(Table))
    {
        if (Settings->bOutputToLog)
        {
            UE_LOG(LogAssetNaming, Warning,
                TEXT("[AssetNaming] No valid PrefixTable; skipping."));
        }
        return true;
    }

    // build list of known prefixes once
    TArray<FString> AllPrefixes;
    AllPrefixes.Reserve(Table->GetRowMap().Num());
    for (auto& Pair : Table->GetRowMap())
    {
        const FAssetPrefixRow* Row = reinterpret_cast<FAssetPrefixRow*>(Pair.Value);
        AllPrefixes.Add(Row->Prefix);
    }

    static const FString Context(TEXT("AssetPrefixLookup"));
    for (int32 i = 0; i < Settings->MaxRenamesPerTick; ++i)
    {
        FAssetData AssetData;
        if (!PendingAssets.Dequeue(AssetData))
        {
            break;
        }

        if (AssetData.AssetClassPath.GetAssetName() == FName("Redirector"))
            continue;

        const FString Key = AssetData.AssetClassPath.GetAssetName().ToString();
        if (const FAssetPrefixRow* Row = Table->FindRow<FAssetPrefixRow>(*Key, Context))
        {
            const FString OldName = AssetData.AssetName.ToString();

        	// if the *current* name already starts with the right prefix, do nothing
        	const FString CurrentName = AssetData.AssetName.ToString();
        	if (CurrentName.StartsWith(Row->Prefix))
        	{
        		continue;
        	}
        	
            // apply strip old prefix helper to remove any existing prefix on asset
            FString BaseName = StripAllKnownAndStrayPrefixes(OldName, AllPrefixes, Settings->bStripOldPrefix);

            const FString NewName = Row->Prefix + BaseName;
            if (OldName == NewName)
                continue;

            // rename 
            FSoftObjectPath OldPath = AssetData.ToSoftObjectPath();
            const FString PackagePath = AssetData.PackagePath.ToString();
            FString NewObjectPathStr = FString::Printf(TEXT("%s/%s.%s"), *PackagePath, *NewName, *NewName);
            FSoftObjectPath NewPath(NewObjectPathStr);

            if (Settings->bOutputToLog)
            {
                UE_LOG(LogAssetNaming, Log, TEXT("[AssetNaming] %s → %s"), *OldPath.ToString(), *NewPath.ToString());
            }

            TArray<FAssetRenameData> Ops;
            Ops.Emplace(OldPath, NewPath);
            FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get().RenameAssets(Ops);
        }
    }

	// Keep ticking
    return true;
}

TSharedRef<FExtender> FAssetNamingPrefixModule::OnExtendAssetViewContextMenu(const TArray<FAssetData>& SelectedAssets)
{
	TSharedRef<FExtender> Extender = MakeShared<FExtender>();

	Extender->AddMenuExtension(
		"GetAssetActions",
		EExtensionHook::After,
		nullptr,
		FMenuExtensionDelegate::CreateLambda(
			[this, SelectedAssets](FMenuBuilder& MenuBuilder)
			{
				// stash them
				CachedSelectedAssets = SelectedAssets;
				CachedSelectedPaths.Empty();

				// start our own section
				MenuBuilder.BeginSection(
					"PrefixRenamerSection",
					LOCTEXT("PrefixRenamerSectionHeading", "Josh Davidson’s Prefix Renamer")
				);

				// your menu item
				MenuBuilder.AddMenuEntry(
					LOCTEXT("PrefixSelectedAssets", "Apply Asset Naming Prefix"),
					LOCTEXT("PrefixSelectedAssetsTooltip", "Run the asset-namer over these assets."),
					FSlateIcon(),
					FUIAction(FExecuteAction::CreateRaw(this, &FAssetNamingPrefixModule::RunPrefixOnAssets))
				);

				// close the section
				MenuBuilder.EndSection();
			}
		)
	);

	return Extender;
}

void FAssetNamingPrefixModule::FillAssetContextMenu(FMenuBuilder& MenuBuilder, TArray<FAssetData> SelectedAssets)
{
	// cache the selection here*
	CachedSelectedAssets = MoveTemp(SelectedAssets);
	CachedSelectedPaths.Empty(); // we know this came from asset-click
	
	MenuBuilder.AddMenuEntry(
		LOCTEXT("PrefixSelectedAssets", "Apply Asset Naming Prefix"),
		LOCTEXT("PrefixSelectedAssetsTooltip", "Run the asset-namer over these assets."),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateRaw(this, &FAssetNamingPrefixModule::RunPrefixOnAssets))
	);
}

TSharedRef<FExtender> FAssetNamingPrefixModule::OnExtendPathViewContextMenu(const TArray<FString>& SelectedPaths)
{
	TSharedRef<FExtender> Extender = MakeShared<FExtender>();

	Extender->AddMenuExtension(
		"FolderContext",
		EExtensionHook::After,
		nullptr,
		FMenuExtensionDelegate::CreateLambda(
			[this, SelectedPaths](FMenuBuilder& MenuBuilder)
			{
				// stash for RunPrefixOnAssets()
				CachedSelectedAssets.Empty();
				CachedSelectedPaths = SelectedPaths;

				// a simple separator and then your menu entry
				MenuBuilder.AddMenuSeparator();
				MenuBuilder.AddMenuEntry(
					LOCTEXT("PrefixFolderAssets",    "Prefix All Assets in Folder"),
					LOCTEXT("PrefixFolderAssetsTooltip",
							"Runs the asset-namer on every asset in these folders."),
					FSlateIcon(),
					FUIAction(
						FExecuteAction::CreateRaw(this, &FAssetNamingPrefixModule::RunPrefixOnAssets)
					)
				);
			}
		)
	);

	return Extender;
}

void FAssetNamingPrefixModule::FillPathContextMenu(FMenuBuilder& MenuBuilder, const TArray<FString> SelectedPaths)
{
	CachedSelectedPaths = SelectedPaths;
	CachedSelectedAssets.Empty(); // we know this came from folder-click
	
	MenuBuilder.AddMenuEntry(
		LOCTEXT("PrefixFolderAssets", "Prefix All Assets in Folder"),
		LOCTEXT("PrefixFolderAssetsTooltip", "Runs the asset-namer on every asset in these folders."),
		FSlateIcon(),
		FUIAction(
			FExecuteAction::CreateRaw(this, &FAssetNamingPrefixModule::RunPrefixOnAssets)
		)
	);
}

void FAssetNamingPrefixModule::RunPrefixOnAssets()
{
	// copy out and then clear the cache so we don't accidentally reuse it
	TArray<FAssetData> Assets = MoveTemp(CachedSelectedAssets);
	TArray<FString> Paths  = MoveTemp(CachedSelectedPaths);
	CachedSelectedAssets.Empty();
	CachedSelectedPaths.Empty();

	// if assets were right-clicked, handle them
	if (Assets.Num() > 0)
	{
		ProcessPrefixing(Assets);
		return;
	}

	// otherwise, if folder(s) were clicked, gather assets under those paths
	if (Paths.Num() > 0)
	{
		FAssetRegistryModule& ARM = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
		for (const FString& Folder : Paths)
		{
			TArray<FAssetData> PathAssets;
			ARM.Get().GetAssetsByPath(*Folder, PathAssets, /*bRecursive=*/true);
			Assets.Append(MoveTemp(PathAssets));
		}
	}

	if (Assets.Num() == 0)
	{
		// nothing to do
		return;
	}

	ProcessPrefixing(Assets);
}

void FAssetNamingPrefixModule::ProcessPrefixing(const TArray<FAssetData>& Assets)
{
	const auto* Settings = GetDefault<UAssetNamingPrefixSettings>();
    if (!IsValid(Settings) || !Settings->PrefixTable.IsNull() == false)
    {
        return;
    }

    // Load the DataTable
    UDataTable* Table = Settings->PrefixTable.LoadSynchronous();
    static const FString Context(TEXT("AssetPrefixLookup"));

    // Gather all known prefixes
    TArray<FString> AllPrefixes;
    AllPrefixes.Reserve(Table->GetRowMap().Num());
    for (auto& Pair : Table->GetRowMap())
    {
        const FAssetPrefixRow* Row = reinterpret_cast<FAssetPrefixRow*>(Pair.Value);
        AllPrefixes.Add(Row->Prefix);
    }

    // Build rename list
    TArray<FAssetRenameData> RenameOps;
    RenameOps.Reserve(Assets.Num());

    for (const FAssetData& AssetData : Assets)
    {
        if (!AssetData.IsValid() ||
            AssetData.AssetClassPath.GetAssetName() == FName("Redirector"))
        {
            continue;
        }

        // Which prefix _should_ apply?
        const FString Key = AssetData.AssetClassPath.GetAssetName().ToString();
        const FAssetPrefixRow* DesiredRow = Table->FindRow<FAssetPrefixRow>(*Key, Context);
        if (!DesiredRow)
        {
            continue;
        }

        // Strip old prefixes (known & stray) in one shot
        const FString OldName = AssetData.AssetName.ToString();
        const FString BaseName = StripAllKnownAndStrayPrefixes(OldName, AllPrefixes, Settings->bStripOldPrefix);

        // Build the final new name
        const FString NewName = DesiredRow->Prefix + BaseName;
        if (OldName == NewName)
        {
            continue; // already correct
        }

        // Queue up the rename
        if (UObject* AssetObj = AssetData.GetAsset())
        {
            const FString FolderPath = AssetData.PackagePath.ToString();
            if (Settings->bOutputToLog)
            {
                UE_LOG(LogAssetNaming, Log,
                    TEXT("[AssetNaming] %s → %s/%s"),
                    *AssetData.ObjectPath.ToString(),
                    *FolderPath,
                    *NewName
                );
            }
            RenameOps.Emplace(AssetObj, FolderPath, NewName);
        }
        else if (Settings->bOutputToLog)
        {
            UE_LOG(LogAssetNaming, Warning, TEXT("[AssetNaming] Couldn’t load %s"), *AssetData.ObjectPath.ToString());
        }
    }

    // 4) Execute the batch rename
    if (RenameOps.Num() > 0)
    {
        FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get().RenameAssets(RenameOps);
    }
}

FString FAssetNamingPrefixModule::StripAllKnownAndStrayPrefixes(const FString& InName,
	const TArray<FString>& AllPrefixes, bool bStripOldPrefix)
{
	if (!bStripOldPrefix)
	{
		return InName;
	}

	// strip any of our known prefixes
	FString Base = InName;
	for (const FString& P : AllPrefixes)
	{
		if (Base.StartsWith(P))
		{
			Base = Base.Mid(P.Len());
			break;
		}
	}

	// strip any remaining leading “Something_”
	int32 UPos = INDEX_NONE;
	if (Base.FindChar('_', UPos) && UPos > 0)
	{
		Base = Base.Mid(UPos + 1);
	}

	return Base;
}

void FAssetNamingPrefixModule::HandleRegistryFilesLoaded()
{
	// Now hook only for *new* assets
	FAssetRegistryModule& ARM = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	AssetAddedHandle = ARM.Get().OnAssetAdded().AddRaw(this, &FAssetNamingPrefixModule::OnAssetRegistryAssetAdded);

	// Get the ticker intervals from the plugin settings. Defaults to 0.5s intervals 
	const auto* Settings = GetDefault<UAssetNamingPrefixSettings>();
	TickDelegate = FTickerDelegate::CreateRaw(this, &FAssetNamingPrefixModule::TickProcessPending);
	TickHandle = FTSTicker::GetCoreTicker().AddTicker(TickDelegate, Settings->TickInterval);
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FAssetNamingPrefixModule, AssetNamingPrefix)