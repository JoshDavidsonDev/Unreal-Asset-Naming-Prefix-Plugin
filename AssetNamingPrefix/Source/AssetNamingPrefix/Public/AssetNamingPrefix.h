// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FAssetNamingPrefixModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	
	// Called once the registry has finished its initial scan
	void HandleRegistryFilesLoaded();

	// Called immediately when any new asset appears in the registry
	void OnAssetRegistryAssetAdded(const FAssetData& AssetData);

	// Our ticker; called ~every half-second
	bool TickProcessPending(float DeltaTime);

	// Holds all assets waiting to be renamed
	TQueue<FAssetData, EQueueMode::Spsc> PendingAssets;

	// Our ticker delegate handle
	FTickerDelegate TickDelegate;
	FTSTicker::FDelegateHandle  TickHandle;
	
	// Registry hook handle
	FDelegateHandle  AssetAddedHandle;
	
	// ContentBrowser menu extenders
	TSharedRef<FExtender> OnExtendAssetViewContextMenu(const TArray<FAssetData>& SelectedAssets);
	void FillAssetContextMenu(FMenuBuilder& MenuBuilder, TArray<FAssetData> SelectedAssets);
	
	TSharedRef<FExtender> OnExtendPathViewContextMenu(const TArray<FString>& SelectedPaths);
	void FillPathContextMenu(FMenuBuilder& MenuBuilder, const TArray<FString> SelectedPaths);

	// The actual worker
	void RunPrefixOnAssets();
	void ProcessPrefixing(const TArray<FAssetData>& Assets);

	// Helpers
	static FString StripAllKnownAndStrayPrefixes(const FString& InName, const TArray<FString>& AllPrefixes, bool bStripOldPrefix);

	// Keep handles so we can unhook
	FDelegateHandle AssetViewExtenderHandle;
	FDelegateHandle PathViewExtenderHandle;

	// Stash of the last-built selection
	TArray<FAssetData> CachedSelectedAssets;
	TArray<FString> CachedSelectedPaths;

	int32 AssetViewExtenderIndex = INDEX_NONE;
	int32 PathViewExtenderIndex  = INDEX_NONE;
};
