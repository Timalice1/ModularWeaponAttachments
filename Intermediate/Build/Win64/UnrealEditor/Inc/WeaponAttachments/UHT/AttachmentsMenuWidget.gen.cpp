// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WeaponAttachments/Public/UI/AttachmentsMenuWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAttachmentsMenuWidget() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
UMG_API UClass* Z_Construct_UClass_UOverlay_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UMG_API UClass* Z_Construct_UClass_UVerticalBox_NoRegister();
UPackage* Z_Construct_UPackage__Script_WeaponAttachments();
WEAPONATTACHMENTS_API UClass* Z_Construct_UClass_UAttachmentsMenuButton_NoRegister();
WEAPONATTACHMENTS_API UClass* Z_Construct_UClass_UAttachmentsMenuWidget();
WEAPONATTACHMENTS_API UClass* Z_Construct_UClass_UAttachmentsMenuWidget_NoRegister();
WEAPONATTACHMENTS_API UClass* Z_Construct_UClass_UAttachmentsPanel_NoRegister();
WEAPONATTACHMENTS_API UClass* Z_Construct_UClass_UWeaponAttachmentsManager_NoRegister();
// End Cross Module References

// Begin Class UAttachmentsMenuWidget Function TogglePanel
struct Z_Construct_UFunction_UAttachmentsMenuWidget_TogglePanel_Statics
{
	struct AttachmentsMenuWidget_eventTogglePanel_Parms
	{
		UAttachmentsMenuButton* slotButton;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UI/AttachmentsMenuWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_slotButton_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_slotButton;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAttachmentsMenuWidget_TogglePanel_Statics::NewProp_slotButton = { "slotButton", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AttachmentsMenuWidget_eventTogglePanel_Parms, slotButton), Z_Construct_UClass_UAttachmentsMenuButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_slotButton_MetaData), NewProp_slotButton_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAttachmentsMenuWidget_TogglePanel_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAttachmentsMenuWidget_TogglePanel_Statics::NewProp_slotButton,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAttachmentsMenuWidget_TogglePanel_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAttachmentsMenuWidget_TogglePanel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAttachmentsMenuWidget, nullptr, "TogglePanel", nullptr, nullptr, Z_Construct_UFunction_UAttachmentsMenuWidget_TogglePanel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UAttachmentsMenuWidget_TogglePanel_Statics::PropPointers), sizeof(Z_Construct_UFunction_UAttachmentsMenuWidget_TogglePanel_Statics::AttachmentsMenuWidget_eventTogglePanel_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAttachmentsMenuWidget_TogglePanel_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAttachmentsMenuWidget_TogglePanel_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UAttachmentsMenuWidget_TogglePanel_Statics::AttachmentsMenuWidget_eventTogglePanel_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAttachmentsMenuWidget_TogglePanel()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAttachmentsMenuWidget_TogglePanel_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAttachmentsMenuWidget::execTogglePanel)
{
	P_GET_OBJECT(UAttachmentsMenuButton,Z_Param_slotButton);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TogglePanel(Z_Param_slotButton);
	P_NATIVE_END;
}
// End Class UAttachmentsMenuWidget Function TogglePanel

// Begin Class UAttachmentsMenuWidget
void UAttachmentsMenuWidget::StaticRegisterNativesUAttachmentsMenuWidget()
{
	UClass* Class = UAttachmentsMenuWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "TogglePanel", &UAttachmentsMenuWidget::execTogglePanel },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAttachmentsMenuWidget);
UClass* Z_Construct_UClass_UAttachmentsMenuWidget_NoRegister()
{
	return UAttachmentsMenuWidget::StaticClass();
}
struct Z_Construct_UClass_UAttachmentsMenuWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "UI/AttachmentsMenuWidget.h" },
		{ "ModuleRelativePath", "Public/UI/AttachmentsMenuWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_attachmentsComponentRef_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/AttachmentsMenuWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__buttonToPanelMap_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/AttachmentsMenuWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_currentActivePanel_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/AttachmentsMenuWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_slotsList_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/AttachmentsMenuWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_panelsContainer_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/AttachmentsMenuWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_slotButtonTemplate_MetaData[] = {
		{ "Category", "MenuConfig" },
		{ "ModuleRelativePath", "Public/UI/AttachmentsMenuWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_panelTemplate_MetaData[] = {
		{ "Category", "MenuConfig" },
		{ "ModuleRelativePath", "Public/UI/AttachmentsMenuWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_attachmentsComponentRef;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__buttonToPanelMap_ValueProp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__buttonToPanelMap_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp__buttonToPanelMap;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_currentActivePanel;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_slotsList;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_panelsContainer;
	static const UECodeGen_Private::FClassPropertyParams NewProp_slotButtonTemplate;
	static const UECodeGen_Private::FClassPropertyParams NewProp_panelTemplate;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UAttachmentsMenuWidget_TogglePanel, "TogglePanel" }, // 1848441384
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAttachmentsMenuWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAttachmentsMenuWidget_Statics::NewProp_attachmentsComponentRef = { "attachmentsComponentRef", nullptr, (EPropertyFlags)0x0144000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttachmentsMenuWidget, attachmentsComponentRef), Z_Construct_UClass_UWeaponAttachmentsManager_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_attachmentsComponentRef_MetaData), NewProp_attachmentsComponentRef_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAttachmentsMenuWidget_Statics::NewProp__buttonToPanelMap_ValueProp = { "_buttonToPanelMap", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UAttachmentsPanel_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAttachmentsMenuWidget_Statics::NewProp__buttonToPanelMap_Key_KeyProp = { "_buttonToPanelMap_Key", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UAttachmentsMenuButton_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UAttachmentsMenuWidget_Statics::NewProp__buttonToPanelMap = { "_buttonToPanelMap", nullptr, (EPropertyFlags)0x0040008000000008, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttachmentsMenuWidget, _buttonToPanelMap), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__buttonToPanelMap_MetaData), NewProp__buttonToPanelMap_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAttachmentsMenuWidget_Statics::NewProp_currentActivePanel = { "currentActivePanel", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttachmentsMenuWidget, currentActivePanel), Z_Construct_UClass_UAttachmentsPanel_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_currentActivePanel_MetaData), NewProp_currentActivePanel_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAttachmentsMenuWidget_Statics::NewProp_slotsList = { "slotsList", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttachmentsMenuWidget, slotsList), Z_Construct_UClass_UVerticalBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_slotsList_MetaData), NewProp_slotsList_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAttachmentsMenuWidget_Statics::NewProp_panelsContainer = { "panelsContainer", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttachmentsMenuWidget, panelsContainer), Z_Construct_UClass_UOverlay_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_panelsContainer_MetaData), NewProp_panelsContainer_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UAttachmentsMenuWidget_Statics::NewProp_slotButtonTemplate = { "slotButtonTemplate", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttachmentsMenuWidget, slotButtonTemplate), Z_Construct_UClass_UClass, Z_Construct_UClass_UAttachmentsMenuButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_slotButtonTemplate_MetaData), NewProp_slotButtonTemplate_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UAttachmentsMenuWidget_Statics::NewProp_panelTemplate = { "panelTemplate", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttachmentsMenuWidget, panelTemplate), Z_Construct_UClass_UClass, Z_Construct_UClass_UAttachmentsPanel_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_panelTemplate_MetaData), NewProp_panelTemplate_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAttachmentsMenuWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttachmentsMenuWidget_Statics::NewProp_attachmentsComponentRef,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttachmentsMenuWidget_Statics::NewProp__buttonToPanelMap_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttachmentsMenuWidget_Statics::NewProp__buttonToPanelMap_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttachmentsMenuWidget_Statics::NewProp__buttonToPanelMap,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttachmentsMenuWidget_Statics::NewProp_currentActivePanel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttachmentsMenuWidget_Statics::NewProp_slotsList,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttachmentsMenuWidget_Statics::NewProp_panelsContainer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttachmentsMenuWidget_Statics::NewProp_slotButtonTemplate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttachmentsMenuWidget_Statics::NewProp_panelTemplate,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAttachmentsMenuWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UAttachmentsMenuWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_WeaponAttachments,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAttachmentsMenuWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAttachmentsMenuWidget_Statics::ClassParams = {
	&UAttachmentsMenuWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UAttachmentsMenuWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UAttachmentsMenuWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAttachmentsMenuWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UAttachmentsMenuWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAttachmentsMenuWidget()
{
	if (!Z_Registration_Info_UClass_UAttachmentsMenuWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAttachmentsMenuWidget.OuterSingleton, Z_Construct_UClass_UAttachmentsMenuWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAttachmentsMenuWidget.OuterSingleton;
}
template<> WEAPONATTACHMENTS_API UClass* StaticClass<UAttachmentsMenuWidget>()
{
	return UAttachmentsMenuWidget::StaticClass();
}
UAttachmentsMenuWidget::UAttachmentsMenuWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAttachmentsMenuWidget);
UAttachmentsMenuWidget::~UAttachmentsMenuWidget() {}
// End Class UAttachmentsMenuWidget

// Begin Registration
struct Z_CompiledInDeferFile_FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_UI_AttachmentsMenuWidget_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAttachmentsMenuWidget, UAttachmentsMenuWidget::StaticClass, TEXT("UAttachmentsMenuWidget"), &Z_Registration_Info_UClass_UAttachmentsMenuWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAttachmentsMenuWidget), 3247382611U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_UI_AttachmentsMenuWidget_h_454831706(TEXT("/Script/WeaponAttachments"),
	Z_CompiledInDeferFile_FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_UI_AttachmentsMenuWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_UI_AttachmentsMenuWidget_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
