// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AssetNamingPrefix/Public/AssetNamingPrefixSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAssetNamingPrefixSettings() {}

// Begin Cross Module References
ASSETNAMINGPREFIX_API UClass* Z_Construct_UClass_UAssetNamingPrefixSettings();
ASSETNAMINGPREFIX_API UClass* Z_Construct_UClass_UAssetNamingPrefixSettings_NoRegister();
ASSETNAMINGPREFIX_API UScriptStruct* Z_Construct_UScriptStruct_FAssetPrefixRow();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDirectoryPath();
ENGINE_API UClass* Z_Construct_UClass_UDataTable_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
UPackage* Z_Construct_UPackage__Script_AssetNamingPrefix();
// End Cross Module References

// Begin ScriptStruct FAssetPrefixRow
static_assert(std::is_polymorphic<FAssetPrefixRow>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FAssetPrefixRow cannot be polymorphic unless super FTableRowBase is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AssetPrefixRow;
class UScriptStruct* FAssetPrefixRow::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AssetPrefixRow.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AssetPrefixRow.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAssetPrefixRow, (UObject*)Z_Construct_UPackage__Script_AssetNamingPrefix(), TEXT("AssetPrefixRow"));
	}
	return Z_Registration_Info_UScriptStruct_AssetPrefixRow.OuterSingleton;
}
template<> ASSETNAMINGPREFIX_API UScriptStruct* StaticStruct<FAssetPrefixRow>()
{
	return FAssetPrefixRow::StaticStruct();
}
struct Z_Construct_UScriptStruct_FAssetPrefixRow_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/AssetNamingPrefixSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AssetKey_MetaData[] = {
		{ "Category", "AssetNaming" },
		{ "Comment", "/** Asset class name or path key (e.g., \"StaticMesh\", \"/Script/Engine.Texture\") */" },
		{ "ModuleRelativePath", "Public/AssetNamingPrefixSettings.h" },
		{ "ToolTip", "Asset class name or path key (e.g., \"StaticMesh\", \"/Script/Engine.Texture\")" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Prefix_MetaData[] = {
		{ "Category", "AssetNaming" },
		{ "Comment", "/** Prefix to apply (e.g., \"SM\", \"TEX\") */" },
		{ "ModuleRelativePath", "Public/AssetNamingPrefixSettings.h" },
		{ "ToolTip", "Prefix to apply (e.g., \"SM\", \"TEX\")" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Example_MetaData[] = {
		{ "Category", "AssetNaming" },
		{ "Comment", "/** Example of how the rename output will look. E.g BP_MyBlueprint */" },
		{ "ModuleRelativePath", "Public/AssetNamingPrefixSettings.h" },
		{ "ToolTip", "Example of how the rename output will look. E.g BP_MyBlueprint" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_AssetKey;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Prefix;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Example;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAssetPrefixRow>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAssetPrefixRow_Statics::NewProp_AssetKey = { "AssetKey", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAssetPrefixRow, AssetKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AssetKey_MetaData), NewProp_AssetKey_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAssetPrefixRow_Statics::NewProp_Prefix = { "Prefix", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAssetPrefixRow, Prefix), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Prefix_MetaData), NewProp_Prefix_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAssetPrefixRow_Statics::NewProp_Example = { "Example", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAssetPrefixRow, Example), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Example_MetaData), NewProp_Example_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAssetPrefixRow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAssetPrefixRow_Statics::NewProp_AssetKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAssetPrefixRow_Statics::NewProp_Prefix,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAssetPrefixRow_Statics::NewProp_Example,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAssetPrefixRow_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAssetPrefixRow_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_AssetNamingPrefix,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"AssetPrefixRow",
	Z_Construct_UScriptStruct_FAssetPrefixRow_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAssetPrefixRow_Statics::PropPointers),
	sizeof(FAssetPrefixRow),
	alignof(FAssetPrefixRow),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAssetPrefixRow_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAssetPrefixRow_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAssetPrefixRow()
{
	if (!Z_Registration_Info_UScriptStruct_AssetPrefixRow.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AssetPrefixRow.InnerSingleton, Z_Construct_UScriptStruct_FAssetPrefixRow_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_AssetPrefixRow.InnerSingleton;
}
// End ScriptStruct FAssetPrefixRow

// Begin Class UAssetNamingPrefixSettings
void UAssetNamingPrefixSettings::StaticRegisterNativesUAssetNamingPrefixSettings()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAssetNamingPrefixSettings);
UClass* Z_Construct_UClass_UAssetNamingPrefixSettings_NoRegister()
{
	return UAssetNamingPrefixSettings::StaticClass();
}
struct Z_Construct_UClass_UAssetNamingPrefixSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "AssetNamingPrefixSettings.h" },
		{ "ModuleRelativePath", "Public/AssetNamingPrefixSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableAutoPrefix_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "/** Master switch */" },
		{ "DisplayName", "Enable Auto-Prefixing" },
		{ "ModuleRelativePath", "Public/AssetNamingPrefixSettings.h" },
		{ "ToolTip", "Master switch" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowAllPaths_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "/** If true, ignore AllowedPaths and apply prefixes everywhere. */" },
		{ "ModuleRelativePath", "Public/AssetNamingPrefixSettings.h" },
		{ "ToolTip", "If true, ignore AllowedPaths and apply prefixes everywhere." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AllowedPaths_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "/** Where to look for new assets (e.g. \"/Game\", \"/Plugins/MyPlugin\") */" },
		{ "DisplayName", "Allowed Paths" },
		{ "EditCondition", "!bAllowAllPaths" },
		{ "ModuleRelativePath", "Public/AssetNamingPrefixSettings.h" },
		{ "ToolTip", "Where to look for new assets (e.g. \"/Game\", \"/Plugins/MyPlugin\")" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bStripOldPrefix_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "/** If false, any leading \xe2\x80\x9c""Foo_\xe2\x80\x9d that isn\xe2\x80\x99t in your table will be preserved */" },
		{ "ModuleRelativePath", "Public/AssetNamingPrefixSettings.h" },
		{ "ToolTip", "If false, any leading \xe2\x80\x9c""Foo_\xe2\x80\x9d that isn\xe2\x80\x99t in your table will be preserved" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bOutputToLog_MetaData[] = {
		{ "Category", "General" },
		{ "Comment", "/** If true, will update log with rename and show warning for any failed assets to prefix */" },
		{ "DisplayName", "Enable Update Output Log" },
		{ "ModuleRelativePath", "Public/AssetNamingPrefixSettings.h" },
		{ "ToolTip", "If true, will update log with rename and show warning for any failed assets to prefix" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxRenamesPerTick_MetaData[] = {
		{ "Category", "Performance" },
		{ "ClampMax", "20" },
		{ "ClampMin", "1" },
		{ "Comment", "/** How many assets to rename per tick. We do this to try and minimise bottle necks and crashes if you import 100 assets at once. */" },
		{ "ModuleRelativePath", "Public/AssetNamingPrefixSettings.h" },
		{ "ToolTip", "How many assets to rename per tick. We do this to try and minimise bottle necks and crashes if you import 100 assets at once." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TickInterval_MetaData[] = {
		{ "Category", "Performance" },
		{ "ClampMax", "5.0" },
		{ "ClampMin", "0.1" },
		{ "Comment", "/** Seconds between each batch */" },
		{ "ModuleRelativePath", "Public/AssetNamingPrefixSettings.h" },
		{ "ToolTip", "Seconds between each batch" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PrefixTable_MetaData[] = {
		{ "AllowedClasses", "DataTable" },
		{ "Category", "General" },
		{ "Comment", "/** The DataTable that drives Prefix \xe2\x86\x92 AssetClassKey lookups.  Must use FAssetPrefixRow. */" },
		{ "ModuleRelativePath", "Public/AssetNamingPrefixSettings.h" },
		{ "RowType", "AssetPrefixRow" },
		{ "ToolTip", "The DataTable that drives Prefix \xe2\x86\x92 AssetClassKey lookups.  Must use FAssetPrefixRow." },
	};
#endif // WITH_METADATA
	static void NewProp_bEnableAutoPrefix_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableAutoPrefix;
	static void NewProp_bAllowAllPaths_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowAllPaths;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AllowedPaths_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_AllowedPaths;
	static void NewProp_bStripOldPrefix_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStripOldPrefix;
	static void NewProp_bOutputToLog_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bOutputToLog;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxRenamesPerTick;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TickInterval;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_PrefixTable;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAssetNamingPrefixSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
void Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::NewProp_bEnableAutoPrefix_SetBit(void* Obj)
{
	((UAssetNamingPrefixSettings*)Obj)->bEnableAutoPrefix = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::NewProp_bEnableAutoPrefix = { "bEnableAutoPrefix", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAssetNamingPrefixSettings), &Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::NewProp_bEnableAutoPrefix_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableAutoPrefix_MetaData), NewProp_bEnableAutoPrefix_MetaData) };
void Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::NewProp_bAllowAllPaths_SetBit(void* Obj)
{
	((UAssetNamingPrefixSettings*)Obj)->bAllowAllPaths = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::NewProp_bAllowAllPaths = { "bAllowAllPaths", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAssetNamingPrefixSettings), &Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::NewProp_bAllowAllPaths_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowAllPaths_MetaData), NewProp_bAllowAllPaths_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::NewProp_AllowedPaths_Inner = { "AllowedPaths", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDirectoryPath, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::NewProp_AllowedPaths = { "AllowedPaths", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAssetNamingPrefixSettings, AllowedPaths), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AllowedPaths_MetaData), NewProp_AllowedPaths_MetaData) };
void Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::NewProp_bStripOldPrefix_SetBit(void* Obj)
{
	((UAssetNamingPrefixSettings*)Obj)->bStripOldPrefix = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::NewProp_bStripOldPrefix = { "bStripOldPrefix", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAssetNamingPrefixSettings), &Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::NewProp_bStripOldPrefix_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bStripOldPrefix_MetaData), NewProp_bStripOldPrefix_MetaData) };
void Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::NewProp_bOutputToLog_SetBit(void* Obj)
{
	((UAssetNamingPrefixSettings*)Obj)->bOutputToLog = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::NewProp_bOutputToLog = { "bOutputToLog", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UAssetNamingPrefixSettings), &Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::NewProp_bOutputToLog_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bOutputToLog_MetaData), NewProp_bOutputToLog_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::NewProp_MaxRenamesPerTick = { "MaxRenamesPerTick", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAssetNamingPrefixSettings, MaxRenamesPerTick), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxRenamesPerTick_MetaData), NewProp_MaxRenamesPerTick_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::NewProp_TickInterval = { "TickInterval", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAssetNamingPrefixSettings, TickInterval), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TickInterval_MetaData), NewProp_TickInterval_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::NewProp_PrefixTable = { "PrefixTable", nullptr, (EPropertyFlags)0x0014000000004001, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAssetNamingPrefixSettings, PrefixTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PrefixTable_MetaData), NewProp_PrefixTable_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::NewProp_bEnableAutoPrefix,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::NewProp_bAllowAllPaths,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::NewProp_AllowedPaths_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::NewProp_AllowedPaths,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::NewProp_bStripOldPrefix,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::NewProp_bOutputToLog,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::NewProp_MaxRenamesPerTick,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::NewProp_TickInterval,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::NewProp_PrefixTable,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_AssetNamingPrefix,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::ClassParams = {
	&UAssetNamingPrefixSettings::StaticClass,
	"EditorPerProjectUserSettings",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAssetNamingPrefixSettings()
{
	if (!Z_Registration_Info_UClass_UAssetNamingPrefixSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAssetNamingPrefixSettings.OuterSingleton, Z_Construct_UClass_UAssetNamingPrefixSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAssetNamingPrefixSettings.OuterSingleton;
}
template<> ASSETNAMINGPREFIX_API UClass* StaticClass<UAssetNamingPrefixSettings>()
{
	return UAssetNamingPrefixSettings::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAssetNamingPrefixSettings);
UAssetNamingPrefixSettings::~UAssetNamingPrefixSettings() {}
// End Class UAssetNamingPrefixSettings

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_Josh_Documents_My_UE_Tools_PackageTools_AssetPrefixTool_V_3_0_AssetNamingPrefix_HostProject_Plugins_AssetNamingPrefix_Source_AssetNamingPrefix_Public_AssetNamingPrefixSettings_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FAssetPrefixRow::StaticStruct, Z_Construct_UScriptStruct_FAssetPrefixRow_Statics::NewStructOps, TEXT("AssetPrefixRow"), &Z_Registration_Info_UScriptStruct_AssetPrefixRow, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAssetPrefixRow), 577129808U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAssetNamingPrefixSettings, UAssetNamingPrefixSettings::StaticClass, TEXT("UAssetNamingPrefixSettings"), &Z_Registration_Info_UClass_UAssetNamingPrefixSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAssetNamingPrefixSettings), 4078465545U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Josh_Documents_My_UE_Tools_PackageTools_AssetPrefixTool_V_3_0_AssetNamingPrefix_HostProject_Plugins_AssetNamingPrefix_Source_AssetNamingPrefix_Public_AssetNamingPrefixSettings_h_2644841418(TEXT("/Script/AssetNamingPrefix"),
	Z_CompiledInDeferFile_FID_Users_Josh_Documents_My_UE_Tools_PackageTools_AssetPrefixTool_V_3_0_AssetNamingPrefix_HostProject_Plugins_AssetNamingPrefix_Source_AssetNamingPrefix_Public_AssetNamingPrefixSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Josh_Documents_My_UE_Tools_PackageTools_AssetPrefixTool_V_3_0_AssetNamingPrefix_HostProject_Plugins_AssetNamingPrefix_Source_AssetNamingPrefix_Public_AssetNamingPrefixSettings_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Users_Josh_Documents_My_UE_Tools_PackageTools_AssetPrefixTool_V_3_0_AssetNamingPrefix_HostProject_Plugins_AssetNamingPrefix_Source_AssetNamingPrefix_Public_AssetNamingPrefixSettings_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Josh_Documents_My_UE_Tools_PackageTools_AssetPrefixTool_V_3_0_AssetNamingPrefix_HostProject_Plugins_AssetNamingPrefix_Source_AssetNamingPrefix_Public_AssetNamingPrefixSettings_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
