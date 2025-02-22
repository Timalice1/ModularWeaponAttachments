// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WeaponAttachments/Public/UI/AttachmentsPanel.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAttachmentsPanel() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UMG_API UClass* Z_Construct_UClass_UVerticalBox_NoRegister();
UPackage* Z_Construct_UPackage__Script_WeaponAttachments();
WEAPONATTACHMENTS_API UClass* Z_Construct_UClass_UAttachmentsMenuButton_NoRegister();
WEAPONATTACHMENTS_API UClass* Z_Construct_UClass_UAttachmentsPanel();
WEAPONATTACHMENTS_API UClass* Z_Construct_UClass_UAttachmentsPanel_NoRegister();
// End Cross Module References

// Begin Class UAttachmentsPanel
void UAttachmentsPanel::StaticRegisterNativesUAttachmentsPanel()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAttachmentsPanel);
UClass* Z_Construct_UClass_UAttachmentsPanel_NoRegister()
{
	return UAttachmentsPanel::StaticClass();
}
struct Z_Construct_UClass_UAttachmentsPanel_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "UI/AttachmentsPanel.h" },
		{ "ModuleRelativePath", "Public/UI/AttachmentsPanel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_panelLabel_Text_MetaData[] = {
		{ "Category", "PanelConfig" },
		{ "ModuleRelativePath", "Public/UI/AttachmentsPanel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_panelLabel_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/AttachmentsPanel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_attachmentsList_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/AttachmentsPanel.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_slotButtonTemplate_MetaData[] = {
		{ "Category", "MenuConfig" },
		{ "ModuleRelativePath", "Public/UI/AttachmentsPanel.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FTextPropertyParams NewProp_panelLabel_Text;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_panelLabel;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_attachmentsList;
	static const UECodeGen_Private::FClassPropertyParams NewProp_slotButtonTemplate;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAttachmentsPanel>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UAttachmentsPanel_Statics::NewProp_panelLabel_Text = { "panelLabel_Text", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttachmentsPanel, panelLabel_Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_panelLabel_Text_MetaData), NewProp_panelLabel_Text_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAttachmentsPanel_Statics::NewProp_panelLabel = { "panelLabel", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttachmentsPanel, panelLabel), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_panelLabel_MetaData), NewProp_panelLabel_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAttachmentsPanel_Statics::NewProp_attachmentsList = { "attachmentsList", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttachmentsPanel, attachmentsList), Z_Construct_UClass_UVerticalBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_attachmentsList_MetaData), NewProp_attachmentsList_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UAttachmentsPanel_Statics::NewProp_slotButtonTemplate = { "slotButtonTemplate", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttachmentsPanel, slotButtonTemplate), Z_Construct_UClass_UClass, Z_Construct_UClass_UAttachmentsMenuButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_slotButtonTemplate_MetaData), NewProp_slotButtonTemplate_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAttachmentsPanel_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttachmentsPanel_Statics::NewProp_panelLabel_Text,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttachmentsPanel_Statics::NewProp_panelLabel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttachmentsPanel_Statics::NewProp_attachmentsList,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttachmentsPanel_Statics::NewProp_slotButtonTemplate,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAttachmentsPanel_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UAttachmentsPanel_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_WeaponAttachments,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAttachmentsPanel_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAttachmentsPanel_Statics::ClassParams = {
	&UAttachmentsPanel::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UAttachmentsPanel_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UAttachmentsPanel_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAttachmentsPanel_Statics::Class_MetaDataParams), Z_Construct_UClass_UAttachmentsPanel_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAttachmentsPanel()
{
	if (!Z_Registration_Info_UClass_UAttachmentsPanel.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAttachmentsPanel.OuterSingleton, Z_Construct_UClass_UAttachmentsPanel_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAttachmentsPanel.OuterSingleton;
}
template<> WEAPONATTACHMENTS_API UClass* StaticClass<UAttachmentsPanel>()
{
	return UAttachmentsPanel::StaticClass();
}
UAttachmentsPanel::UAttachmentsPanel(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAttachmentsPanel);
UAttachmentsPanel::~UAttachmentsPanel() {}
// End Class UAttachmentsPanel

// Begin Registration
struct Z_CompiledInDeferFile_FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_UI_AttachmentsPanel_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAttachmentsPanel, UAttachmentsPanel::StaticClass, TEXT("UAttachmentsPanel"), &Z_Registration_Info_UClass_UAttachmentsPanel, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAttachmentsPanel), 2818453281U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_UI_AttachmentsPanel_h_3923061787(TEXT("/Script/WeaponAttachments"),
	Z_CompiledInDeferFile_FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_UI_AttachmentsPanel_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_UI_AttachmentsPanel_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
