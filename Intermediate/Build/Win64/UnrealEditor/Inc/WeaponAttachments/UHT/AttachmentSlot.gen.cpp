// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WeaponAttachments/Public/AttachmentSlot.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAttachmentSlot() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UMeshComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_WeaponAttachments();
WEAPONATTACHMENTS_API UScriptStruct* Z_Construct_UScriptStruct_FAttachmentSlot();
// End Cross Module References

// Begin ScriptStruct FAttachmentSlot
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AttachmentSlot;
class UScriptStruct* FAttachmentSlot::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AttachmentSlot.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AttachmentSlot.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAttachmentSlot, (UObject*)Z_Construct_UPackage__Script_WeaponAttachments(), TEXT("AttachmentSlot"));
	}
	return Z_Registration_Info_UScriptStruct_AttachmentSlot.OuterSingleton;
}
template<> WEAPONATTACHMENTS_API UScriptStruct* StaticStruct<FAttachmentSlot>()
{
	return FAttachmentSlot::StaticStruct();
}
struct Z_Construct_UScriptStruct_FAttachmentSlot_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/AttachmentSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotName_MetaData[] = {
		{ "Category", "AttachmentSlot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Use for display name and accessing to slot*/" },
#endif
		{ "ModuleRelativePath", "Public/AttachmentSlot.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Use for display name and accessing to slot" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SocketName_MetaData[] = {
		{ "Category", "AttachmentSlot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Named socket on the parent mesh, where module needs to be attached*/" },
#endif
		{ "ModuleRelativePath", "Public/AttachmentSlot.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Named socket on the parent mesh, where module needs to be attached" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentModule_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/AttachmentSlot.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_parent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/AttachmentSlot.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_SlotName;
	static const UECodeGen_Private::FNamePropertyParams NewProp_SocketName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentModule;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_parent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAttachmentSlot>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FAttachmentSlot_Statics::NewProp_SlotName = { "SlotName", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAttachmentSlot, SlotName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotName_MetaData), NewProp_SlotName_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FAttachmentSlot_Statics::NewProp_SocketName = { "SocketName", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAttachmentSlot, SocketName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SocketName_MetaData), NewProp_SocketName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FAttachmentSlot_Statics::NewProp_CurrentModule = { "CurrentModule", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAttachmentSlot, CurrentModule), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentModule_MetaData), NewProp_CurrentModule_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FAttachmentSlot_Statics::NewProp_parent = { "parent", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAttachmentSlot, parent), Z_Construct_UClass_UMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_parent_MetaData), NewProp_parent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAttachmentSlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAttachmentSlot_Statics::NewProp_SlotName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAttachmentSlot_Statics::NewProp_SocketName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAttachmentSlot_Statics::NewProp_CurrentModule,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAttachmentSlot_Statics::NewProp_parent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAttachmentSlot_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAttachmentSlot_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_WeaponAttachments,
	nullptr,
	&NewStructOps,
	"AttachmentSlot",
	Z_Construct_UScriptStruct_FAttachmentSlot_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAttachmentSlot_Statics::PropPointers),
	sizeof(FAttachmentSlot),
	alignof(FAttachmentSlot),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000005),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAttachmentSlot_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAttachmentSlot_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAttachmentSlot()
{
	if (!Z_Registration_Info_UScriptStruct_AttachmentSlot.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AttachmentSlot.InnerSingleton, Z_Construct_UScriptStruct_FAttachmentSlot_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_AttachmentSlot.InnerSingleton;
}
// End ScriptStruct FAttachmentSlot

// Begin Registration
struct Z_CompiledInDeferFile_FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_AttachmentSlot_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FAttachmentSlot::StaticStruct, Z_Construct_UScriptStruct_FAttachmentSlot_Statics::NewStructOps, TEXT("AttachmentSlot"), &Z_Registration_Info_UScriptStruct_AttachmentSlot, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAttachmentSlot), 1549476362U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_AttachmentSlot_h_2271352823(TEXT("/Script/WeaponAttachments"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_AttachmentSlot_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_AttachmentSlot_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
