// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WeaponAttachments/Public/WeaponAttachmentsManager.h"
#include "WeaponAttachments/Public/Attachment.h"
#include "WeaponAttachments/Public/AttachmentSlot.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWeaponAttachmentsManager() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
ENGINE_API UClass* Z_Construct_UClass_UMeshComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_WeaponAttachments();
WEAPONATTACHMENTS_API UClass* Z_Construct_UClass_UWeaponAttachmentsManager();
WEAPONATTACHMENTS_API UClass* Z_Construct_UClass_UWeaponAttachmentsManager_NoRegister();
WEAPONATTACHMENTS_API UScriptStruct* Z_Construct_UScriptStruct_FAttachmentModuleData();
WEAPONATTACHMENTS_API UScriptStruct* Z_Construct_UScriptStruct_FAttachmentSlot();
// End Cross Module References

// Begin Class UWeaponAttachmentsManager Function GetActiveSlots
struct Z_Construct_UFunction_UWeaponAttachmentsManager_GetActiveSlots_Statics
{
	struct WeaponAttachmentsManager_eventGetActiveSlots_Parms
	{
		TArray<FAttachmentSlot> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/WeaponAttachmentsManager.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWeaponAttachmentsManager_GetActiveSlots_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000008000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FAttachmentSlot, METADATA_PARAMS(0, nullptr) }; // 1549476362
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UWeaponAttachmentsManager_GetActiveSlots_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010008000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WeaponAttachmentsManager_eventGetActiveSlots_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 1549476362
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWeaponAttachmentsManager_GetActiveSlots_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWeaponAttachmentsManager_GetActiveSlots_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWeaponAttachmentsManager_GetActiveSlots_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponAttachmentsManager_GetActiveSlots_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWeaponAttachmentsManager_GetActiveSlots_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UWeaponAttachmentsManager, nullptr, "GetActiveSlots", nullptr, nullptr, Z_Construct_UFunction_UWeaponAttachmentsManager_GetActiveSlots_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponAttachmentsManager_GetActiveSlots_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWeaponAttachmentsManager_GetActiveSlots_Statics::WeaponAttachmentsManager_eventGetActiveSlots_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponAttachmentsManager_GetActiveSlots_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWeaponAttachmentsManager_GetActiveSlots_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UWeaponAttachmentsManager_GetActiveSlots_Statics::WeaponAttachmentsManager_eventGetActiveSlots_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWeaponAttachmentsManager_GetActiveSlots()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWeaponAttachmentsManager_GetActiveSlots_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWeaponAttachmentsManager::execGetActiveSlots)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FAttachmentSlot>*)Z_Param__Result=P_THIS->GetActiveSlots();
	P_NATIVE_END;
}
// End Class UWeaponAttachmentsManager Function GetActiveSlots

// Begin Class UWeaponAttachmentsManager Function InstallModule
struct Z_Construct_UFunction_UWeaponAttachmentsManager_InstallModule_Statics
{
	struct WeaponAttachmentsManager_eventInstallModule_Parms
	{
		FName SlotName;
		FAttachmentModuleData moduleData;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "WeaponAttachmentsManager" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * @brief Install new module to required slot\n     * @param SlotName required slot name\n     * @param moduleData new module data to install\n     */" },
#endif
		{ "ModuleRelativePath", "Public/WeaponAttachmentsManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Install new module to required slot\n@param SlotName required slot name\n@param moduleData new module data to install" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_moduleData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_SlotName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_moduleData;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UWeaponAttachmentsManager_InstallModule_Statics::NewProp_SlotName = { "SlotName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WeaponAttachmentsManager_eventInstallModule_Parms, SlotName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotName_MetaData), NewProp_SlotName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UWeaponAttachmentsManager_InstallModule_Statics::NewProp_moduleData = { "moduleData", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WeaponAttachmentsManager_eventInstallModule_Parms, moduleData), Z_Construct_UScriptStruct_FAttachmentModuleData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_moduleData_MetaData), NewProp_moduleData_MetaData) }; // 2842513527
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWeaponAttachmentsManager_InstallModule_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWeaponAttachmentsManager_InstallModule_Statics::NewProp_SlotName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWeaponAttachmentsManager_InstallModule_Statics::NewProp_moduleData,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponAttachmentsManager_InstallModule_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWeaponAttachmentsManager_InstallModule_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UWeaponAttachmentsManager, nullptr, "InstallModule", nullptr, nullptr, Z_Construct_UFunction_UWeaponAttachmentsManager_InstallModule_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponAttachmentsManager_InstallModule_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWeaponAttachmentsManager_InstallModule_Statics::WeaponAttachmentsManager_eventInstallModule_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponAttachmentsManager_InstallModule_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWeaponAttachmentsManager_InstallModule_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UWeaponAttachmentsManager_InstallModule_Statics::WeaponAttachmentsManager_eventInstallModule_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWeaponAttachmentsManager_InstallModule()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWeaponAttachmentsManager_InstallModule_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWeaponAttachmentsManager::execInstallModule)
{
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_SlotName);
	P_GET_STRUCT_REF(FAttachmentModuleData,Z_Param_Out_moduleData);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InstallModule(Z_Param_Out_SlotName,Z_Param_Out_moduleData);
	P_NATIVE_END;
}
// End Class UWeaponAttachmentsManager Function InstallModule

// Begin Class UWeaponAttachmentsManager Function RemoveModule
struct Z_Construct_UFunction_UWeaponAttachmentsManager_RemoveModule_Statics
{
	struct WeaponAttachmentsManager_eventRemoveModule_Parms
	{
		FName SlotName;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "WeaponAttachmentsManager" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * @brief Remove current active module from required slot\n     * @param SlotName Required slot name\n     */" },
#endif
		{ "CPP_Default_SlotName", "ModuleSlot" },
		{ "ModuleRelativePath", "Public/WeaponAttachmentsManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "@brief Remove current active module from required slot\n@param SlotName Required slot name" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlotName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_SlotName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UWeaponAttachmentsManager_RemoveModule_Statics::NewProp_SlotName = { "SlotName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WeaponAttachmentsManager_eventRemoveModule_Parms, SlotName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlotName_MetaData), NewProp_SlotName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWeaponAttachmentsManager_RemoveModule_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWeaponAttachmentsManager_RemoveModule_Statics::NewProp_SlotName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponAttachmentsManager_RemoveModule_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWeaponAttachmentsManager_RemoveModule_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UWeaponAttachmentsManager, nullptr, "RemoveModule", nullptr, nullptr, Z_Construct_UFunction_UWeaponAttachmentsManager_RemoveModule_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponAttachmentsManager_RemoveModule_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWeaponAttachmentsManager_RemoveModule_Statics::WeaponAttachmentsManager_eventRemoveModule_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponAttachmentsManager_RemoveModule_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWeaponAttachmentsManager_RemoveModule_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UWeaponAttachmentsManager_RemoveModule_Statics::WeaponAttachmentsManager_eventRemoveModule_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWeaponAttachmentsManager_RemoveModule()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWeaponAttachmentsManager_RemoveModule_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWeaponAttachmentsManager::execRemoveModule)
{
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_SlotName);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RemoveModule(Z_Param_Out_SlotName);
	P_NATIVE_END;
}
// End Class UWeaponAttachmentsManager Function RemoveModule

// Begin Class UWeaponAttachmentsManager Function SetBaseWeaponMeshComponent
struct Z_Construct_UFunction_UWeaponAttachmentsManager_SetBaseWeaponMeshComponent_Statics
{
	struct WeaponAttachmentsManager_eventSetBaseWeaponMeshComponent_Parms
	{
		UMeshComponent* baseWeaponMesh;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/WeaponAttachmentsManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_baseWeaponMesh_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_baseWeaponMesh;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UWeaponAttachmentsManager_SetBaseWeaponMeshComponent_Statics::NewProp_baseWeaponMesh = { "baseWeaponMesh", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WeaponAttachmentsManager_eventSetBaseWeaponMeshComponent_Parms, baseWeaponMesh), Z_Construct_UClass_UMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_baseWeaponMesh_MetaData), NewProp_baseWeaponMesh_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UWeaponAttachmentsManager_SetBaseWeaponMeshComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UWeaponAttachmentsManager_SetBaseWeaponMeshComponent_Statics::NewProp_baseWeaponMesh,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponAttachmentsManager_SetBaseWeaponMeshComponent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UWeaponAttachmentsManager_SetBaseWeaponMeshComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UWeaponAttachmentsManager, nullptr, "SetBaseWeaponMeshComponent", nullptr, nullptr, Z_Construct_UFunction_UWeaponAttachmentsManager_SetBaseWeaponMeshComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponAttachmentsManager_SetBaseWeaponMeshComponent_Statics::PropPointers), sizeof(Z_Construct_UFunction_UWeaponAttachmentsManager_SetBaseWeaponMeshComponent_Statics::WeaponAttachmentsManager_eventSetBaseWeaponMeshComponent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UWeaponAttachmentsManager_SetBaseWeaponMeshComponent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UWeaponAttachmentsManager_SetBaseWeaponMeshComponent_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UWeaponAttachmentsManager_SetBaseWeaponMeshComponent_Statics::WeaponAttachmentsManager_eventSetBaseWeaponMeshComponent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UWeaponAttachmentsManager_SetBaseWeaponMeshComponent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UWeaponAttachmentsManager_SetBaseWeaponMeshComponent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UWeaponAttachmentsManager::execSetBaseWeaponMeshComponent)
{
	P_GET_OBJECT(UMeshComponent,Z_Param_baseWeaponMesh);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetBaseWeaponMeshComponent(Z_Param_baseWeaponMesh);
	P_NATIVE_END;
}
// End Class UWeaponAttachmentsManager Function SetBaseWeaponMeshComponent

// Begin Class UWeaponAttachmentsManager
void UWeaponAttachmentsManager::StaticRegisterNativesUWeaponAttachmentsManager()
{
	UClass* Class = UWeaponAttachmentsManager::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetActiveSlots", &UWeaponAttachmentsManager::execGetActiveSlots },
		{ "InstallModule", &UWeaponAttachmentsManager::execInstallModule },
		{ "RemoveModule", &UWeaponAttachmentsManager::execRemoveModule },
		{ "SetBaseWeaponMeshComponent", &UWeaponAttachmentsManager::execSetBaseWeaponMeshComponent },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UWeaponAttachmentsManager);
UClass* Z_Construct_UClass_UWeaponAttachmentsManager_NoRegister()
{
	return UWeaponAttachmentsManager::StaticClass();
}
struct Z_Construct_UClass_UWeaponAttachmentsManager_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "IncludePath", "WeaponAttachmentsManager.h" },
		{ "ModuleRelativePath", "Public/WeaponAttachmentsManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ownerMeshComponent_MetaData[] = {
		{ "Category", "WeaponAttachmentsManager" },
		{ "EditInline", "true" },
		{ "GetOptions", "GetOwnerSceneComponents" },
		{ "ModuleRelativePath", "Public/WeaponAttachmentsManager.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_attachmentSlots_MetaData[] = {
		{ "Category", "AttachmentsSystem" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Default weapon attachment slots (persistant)*/" },
#endif
		{ "ModuleRelativePath", "Public/WeaponAttachmentsManager.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Default weapon attachment slots (persistant)" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ownerMeshComponent;
	static const UECodeGen_Private::FStructPropertyParams NewProp_attachmentSlots_ElementProp;
	static const UECodeGen_Private::FSetPropertyParams NewProp_attachmentSlots;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UWeaponAttachmentsManager_GetActiveSlots, "GetActiveSlots" }, // 3926056747
		{ &Z_Construct_UFunction_UWeaponAttachmentsManager_InstallModule, "InstallModule" }, // 468147772
		{ &Z_Construct_UFunction_UWeaponAttachmentsManager_RemoveModule, "RemoveModule" }, // 2898278761
		{ &Z_Construct_UFunction_UWeaponAttachmentsManager_SetBaseWeaponMeshComponent, "SetBaseWeaponMeshComponent" }, // 177428404
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UWeaponAttachmentsManager>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UWeaponAttachmentsManager_Statics::NewProp_ownerMeshComponent = { "ownerMeshComponent", nullptr, (EPropertyFlags)0x0124080000090009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponAttachmentsManager, ownerMeshComponent), Z_Construct_UClass_UMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ownerMeshComponent_MetaData), NewProp_ownerMeshComponent_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UWeaponAttachmentsManager_Statics::NewProp_attachmentSlots_ElementProp = { "attachmentSlots", nullptr, (EPropertyFlags)0x0000008000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FAttachmentSlot, METADATA_PARAMS(0, nullptr) }; // 1549476362
static_assert(TModels_V<CGetTypeHashable, FAttachmentSlot>, "The structure 'FAttachmentSlot' is used in a TSet but does not have a GetValueTypeHash defined");
const UECodeGen_Private::FSetPropertyParams Z_Construct_UClass_UWeaponAttachmentsManager_Statics::NewProp_attachmentSlots = { "attachmentSlots", nullptr, (EPropertyFlags)0x0020088000010005, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UWeaponAttachmentsManager, attachmentSlots), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_attachmentSlots_MetaData), NewProp_attachmentSlots_MetaData) }; // 1549476362
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UWeaponAttachmentsManager_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponAttachmentsManager_Statics::NewProp_ownerMeshComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponAttachmentsManager_Statics::NewProp_attachmentSlots_ElementProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UWeaponAttachmentsManager_Statics::NewProp_attachmentSlots,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UWeaponAttachmentsManager_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UWeaponAttachmentsManager_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_WeaponAttachments,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UWeaponAttachmentsManager_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UWeaponAttachmentsManager_Statics::ClassParams = {
	&UWeaponAttachmentsManager::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UWeaponAttachmentsManager_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UWeaponAttachmentsManager_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UWeaponAttachmentsManager_Statics::Class_MetaDataParams), Z_Construct_UClass_UWeaponAttachmentsManager_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UWeaponAttachmentsManager()
{
	if (!Z_Registration_Info_UClass_UWeaponAttachmentsManager.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UWeaponAttachmentsManager.OuterSingleton, Z_Construct_UClass_UWeaponAttachmentsManager_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UWeaponAttachmentsManager.OuterSingleton;
}
template<> WEAPONATTACHMENTS_API UClass* StaticClass<UWeaponAttachmentsManager>()
{
	return UWeaponAttachmentsManager::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UWeaponAttachmentsManager);
UWeaponAttachmentsManager::~UWeaponAttachmentsManager() {}
// End Class UWeaponAttachmentsManager

// Begin Registration
struct Z_CompiledInDeferFile_FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_WeaponAttachmentsManager_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UWeaponAttachmentsManager, UWeaponAttachmentsManager::StaticClass, TEXT("UWeaponAttachmentsManager"), &Z_Registration_Info_UClass_UWeaponAttachmentsManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UWeaponAttachmentsManager), 2155301320U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_WeaponAttachmentsManager_h_219414147(TEXT("/Script/WeaponAttachments"),
	Z_CompiledInDeferFile_FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_WeaponAttachmentsManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_WeaponAttachmentsManager_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
