// This product was developed by Josh Davidson

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AssetNamingPrefixSettings.generated.h"

USTRUCT(BlueprintType)
struct FAssetPrefixRow : public FTableRowBase
{
	GENERATED_BODY()

	/** Asset class name or path key (e.g., "StaticMesh", "/Script/Engine.Texture") */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AssetNaming")
	FString AssetKey;

	/** Prefix to apply (e.g., "SM", "TEX") */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AssetNaming")
	FString Prefix;

	/** Example of how the rename output will look. E.g BP_MyBlueprint */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AssetNaming")
	FString Example;
};

UCLASS(config=EditorPerProjectUserSettings, defaultconfig, BlueprintType)
class ASSETNAMINGPREFIX_API UAssetNamingPrefixSettings : public UObject
{
	GENERATED_BODY()

public:
	UAssetNamingPrefixSettings()
	{
		bEnableAutoPrefix = true;
		AllowedPaths = { FDirectoryPath{ TEXT("/Game") } };
		MaxRenamesPerTick = 5;
		TickInterval = 0.5f;
		bOutputToLog = true;
		bAllowAllPaths = false;
		bStripOldPrefix = true;
		// PrefixTable left null by default; user must wire it up. This is incase the default DT is stored in a different place on the users machine
	}
	
	/** Master switch */
	UPROPERTY(EditAnywhere, config, Category="General", meta=(DisplayName="Enable Auto-Prefixing"))
	bool bEnableAutoPrefix = true;

	/** If true, ignore AllowedPaths and apply prefixes everywhere. */
	UPROPERTY(EditAnywhere, config, Category="General")
	bool bAllowAllPaths = false;

	/** Where to look for new assets (e.g. "/Game", "/Plugins/MyPlugin") */
	UPROPERTY(EditAnywhere, config, Category="General", meta=(DisplayName="Allowed Paths"), meta=(EditCondition="!bAllowAllPaths"))
	TArray<FDirectoryPath> AllowedPaths;

	/** If false, any leading “Foo_” that isn’t in your table will be preserved */
	UPROPERTY(EditAnywhere, config, Category="General")
	bool bStripOldPrefix;

	/** If true, will update log with rename and show warning for any failed assets to prefix */
	UPROPERTY(EditAnywhere, config, Category="General", meta=(DisplayName="Enable Update Output Log"))
	bool bOutputToLog = true;

	/** How many assets to rename per tick. We do this to try and minimise bottle necks and crashes if you import 100 assets at once. */
	UPROPERTY(EditAnywhere, config, Category="Performance", meta=(ClampMin="1", ClampMax="20"))
	int32 MaxRenamesPerTick = 5;

	/** Seconds between each batch */
	UPROPERTY(EditAnywhere, config, Category="Performance", meta=(ClampMin="0.1", ClampMax="5.0"))
	float TickInterval = 0.5f;
	
	/** The DataTable that drives Prefix → AssetClassKey lookups.  Must use FAssetPrefixRow. */
	UPROPERTY(EditAnywhere, config, Category="General", meta=(AllowedClasses="DataTable", RowType="AssetPrefixRow"))
	TSoftObjectPtr<UDataTable> PrefixTable = nullptr;
	
};
