// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WeaponAttachments/Public/Attachment.h"
#include "WeaponAttachments/Public/AttachmentSlot.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAttachment() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
UPackage* Z_Construct_UPackage__Script_WeaponAttachments();
WEAPONATTACHMENTS_API UScriptStruct* Z_Construct_UScriptStruct_FAttachmentModuleData();
WEAPONATTACHMENTS_API UScriptStruct* Z_Construct_UScriptStruct_FAttachmentSlot();
// End Cross Module References

// Begin ScriptStruct FAttachmentModuleData
static_assert(std::is_polymorphic<FAttachmentModuleData>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FAttachmentModuleData cannot be polymorphic unless super FTableRowBase is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AttachmentModuleData;
class UScriptStruct* FAttachmentModuleData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AttachmentModuleData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AttachmentModuleData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAttachmentModuleData, (UObject*)Z_Construct_UPackage__Script_WeaponAttachments(), TEXT("AttachmentModuleData"));
	}
	return Z_Registration_Info_UScriptStruct_AttachmentModuleData.OuterSingleton;
}
template<> WEAPONATTACHMENTS_API UScriptStruct* StaticStruct<FAttachmentModuleData>()
{
	return FAttachmentModuleData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FAttachmentModuleData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Attachment.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[] = {
		{ "Category", "BaseModuleParam" },
		{ "ModuleRelativePath", "Public/Attachment.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_childSlots_MetaData[] = {
		{ "Category", "BaseModuleParam" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*Child attachment slots*/" },
#endif
		{ "ModuleRelativePath", "Public/Attachment.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Child attachment slots" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Mesh;
	static const UECodeGen_Private::FStructPropertyParams NewProp_childSlots_ElementProp;
	static const UECodeGen_Private::FSetPropertyParams NewProp_childSlots;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAttachmentModuleData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FAttachmentModuleData_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAttachmentModuleData, Mesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mesh_MetaData), NewProp_Mesh_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAttachmentModuleData_Statics::NewProp_childSlots_ElementProp = { "childSlots", nullptr, (EPropertyFlags)0x0000008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FAttachmentSlot, METADATA_PARAMS(0, nullptr) }; // 1549476362
static_assert(TModels_V<CGetTypeHashable, FAttachmentSlot>, "The structure 'FAttachmentSlot' is used in a TSet but does not have a GetValueTypeHash defined");
const UECodeGen_Private::FSetPropertyParams Z_Construct_UScriptStruct_FAttachmentModuleData_Statics::NewProp_childSlots = { "childSlots", nullptr, (EPropertyFlags)0x0010008000010005, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAttachmentModuleData, childSlots), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_childSlots_MetaData), NewProp_childSlots_MetaData) }; // 1549476362
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAttachmentModuleData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAttachmentModuleData_Statics::NewProp_Mesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAttachmentModuleData_Statics::NewProp_childSlots_ElementProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAttachmentModuleData_Statics::NewProp_childSlots,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAttachmentModuleData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAttachmentModuleData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_WeaponAttachments,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"AttachmentModuleData",
	Z_Construct_UScriptStruct_FAttachmentModuleData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAttachmentModuleData_Statics::PropPointers),
	sizeof(FAttachmentModuleData),
	alignof(FAttachmentModuleData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000005),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAttachmentModuleData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAttachmentModuleData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAttachmentModuleData()
{
	if (!Z_Registration_Info_UScriptStruct_AttachmentModuleData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AttachmentModuleData.InnerSingleton, Z_Construct_UScriptStruct_FAttachmentModuleData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_AttachmentModuleData.InnerSingleton;
}
// End ScriptStruct FAttachmentModuleData

// Begin Registration
struct Z_CompiledInDeferFile_FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_Attachment_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FAttachmentModuleData::StaticStruct, Z_Construct_UScriptStruct_FAttachmentModuleData_Statics::NewStructOps, TEXT("AttachmentModuleData"), &Z_Registration_Info_UScriptStruct_AttachmentModuleData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAttachmentModuleData), 2842513527U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_Attachment_h_1233238061(TEXT("/Script/WeaponAttachments"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_Attachment_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_Attachment_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
