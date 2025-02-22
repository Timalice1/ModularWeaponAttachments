// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WeaponAttachments/Public/UI/AttachmentsMenuButton.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAttachmentsMenuButton() {}

// Begin Cross Module References
UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_WeaponAttachments();
WEAPONATTACHMENTS_API UClass* Z_Construct_UClass_UAttachmentsMenuButton();
WEAPONATTACHMENTS_API UClass* Z_Construct_UClass_UAttachmentsMenuButton_NoRegister();
WEAPONATTACHMENTS_API UFunction* Z_Construct_UDelegateFunction_WeaponAttachments_OnClickedSignature__DelegateSignature();
// End Cross Module References

// Begin Delegate FOnClickedSignature
struct Z_Construct_UDelegateFunction_WeaponAttachments_OnClickedSignature__DelegateSignature_Statics
{
	struct _Script_WeaponAttachments_eventOnClickedSignature_Parms
	{
		UAttachmentsMenuButton* clickedButton;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UI/AttachmentsMenuButton.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_clickedButton_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_clickedButton;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_WeaponAttachments_OnClickedSignature__DelegateSignature_Statics::NewProp_clickedButton = { "clickedButton", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_WeaponAttachments_eventOnClickedSignature_Parms, clickedButton), Z_Construct_UClass_UAttachmentsMenuButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_clickedButton_MetaData), NewProp_clickedButton_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_WeaponAttachments_OnClickedSignature__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_WeaponAttachments_OnClickedSignature__DelegateSignature_Statics::NewProp_clickedButton,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_WeaponAttachments_OnClickedSignature__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_WeaponAttachments_OnClickedSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_WeaponAttachments, nullptr, "OnClickedSignature__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_WeaponAttachments_OnClickedSignature__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_WeaponAttachments_OnClickedSignature__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_WeaponAttachments_OnClickedSignature__DelegateSignature_Statics::_Script_WeaponAttachments_eventOnClickedSignature_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_WeaponAttachments_OnClickedSignature__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_WeaponAttachments_OnClickedSignature__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_WeaponAttachments_OnClickedSignature__DelegateSignature_Statics::_Script_WeaponAttachments_eventOnClickedSignature_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_WeaponAttachments_OnClickedSignature__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_WeaponAttachments_OnClickedSignature__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnClickedSignature_DelegateWrapper(const FMulticastScriptDelegate& OnClickedSignature, UAttachmentsMenuButton* clickedButton)
{
	struct _Script_WeaponAttachments_eventOnClickedSignature_Parms
	{
		UAttachmentsMenuButton* clickedButton;
	};
	_Script_WeaponAttachments_eventOnClickedSignature_Parms Parms;
	Parms.clickedButton=clickedButton;
	OnClickedSignature.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnClickedSignature

// Begin Class UAttachmentsMenuButton Function OnButtonClicked
struct Z_Construct_UFunction_UAttachmentsMenuButton_OnButtonClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UI/AttachmentsMenuButton.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAttachmentsMenuButton_OnButtonClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAttachmentsMenuButton, nullptr, "OnButtonClicked", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAttachmentsMenuButton_OnButtonClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAttachmentsMenuButton_OnButtonClicked_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UAttachmentsMenuButton_OnButtonClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAttachmentsMenuButton_OnButtonClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAttachmentsMenuButton::execOnButtonClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnButtonClicked();
	P_NATIVE_END;
}
// End Class UAttachmentsMenuButton Function OnButtonClicked

// Begin Class UAttachmentsMenuButton
void UAttachmentsMenuButton::StaticRegisterNativesUAttachmentsMenuButton()
{
	UClass* Class = UAttachmentsMenuButton::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnButtonClicked", &UAttachmentsMenuButton::execOnButtonClicked },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAttachmentsMenuButton);
UClass* Z_Construct_UClass_UAttachmentsMenuButton_NoRegister()
{
	return UAttachmentsMenuButton::StaticClass();
}
struct Z_Construct_UClass_UAttachmentsMenuButton_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "UI/AttachmentsMenuButton.h" },
		{ "ModuleRelativePath", "Public/UI/AttachmentsMenuButton.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_buttonLabelText_MetaData[] = {
		{ "Category", "ButtonConfig" },
		{ "ModuleRelativePath", "Public/UI/AttachmentsMenuButton.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnClick_MetaData[] = {
		{ "ModuleRelativePath", "Public/UI/AttachmentsMenuButton.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_button_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/AttachmentsMenuButton.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_buttonLabel_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/AttachmentsMenuButton.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FTextPropertyParams NewProp_buttonLabelText;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnClick;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_button;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_buttonLabel;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UAttachmentsMenuButton_OnButtonClicked, "OnButtonClicked" }, // 3945711315
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAttachmentsMenuButton>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UAttachmentsMenuButton_Statics::NewProp_buttonLabelText = { "buttonLabelText", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttachmentsMenuButton, buttonLabelText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_buttonLabelText_MetaData), NewProp_buttonLabelText_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UAttachmentsMenuButton_Statics::NewProp_OnClick = { "OnClick", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttachmentsMenuButton, OnClick), Z_Construct_UDelegateFunction_WeaponAttachments_OnClickedSignature__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnClick_MetaData), NewProp_OnClick_MetaData) }; // 2769696245
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAttachmentsMenuButton_Statics::NewProp_button = { "button", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttachmentsMenuButton, button), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_button_MetaData), NewProp_button_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UAttachmentsMenuButton_Statics::NewProp_buttonLabel = { "buttonLabel", nullptr, (EPropertyFlags)0x0124080000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAttachmentsMenuButton, buttonLabel), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_buttonLabel_MetaData), NewProp_buttonLabel_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAttachmentsMenuButton_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttachmentsMenuButton_Statics::NewProp_buttonLabelText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttachmentsMenuButton_Statics::NewProp_OnClick,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttachmentsMenuButton_Statics::NewProp_button,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAttachmentsMenuButton_Statics::NewProp_buttonLabel,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAttachmentsMenuButton_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UAttachmentsMenuButton_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_WeaponAttachments,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAttachmentsMenuButton_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAttachmentsMenuButton_Statics::ClassParams = {
	&UAttachmentsMenuButton::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UAttachmentsMenuButton_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UAttachmentsMenuButton_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAttachmentsMenuButton_Statics::Class_MetaDataParams), Z_Construct_UClass_UAttachmentsMenuButton_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAttachmentsMenuButton()
{
	if (!Z_Registration_Info_UClass_UAttachmentsMenuButton.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAttachmentsMenuButton.OuterSingleton, Z_Construct_UClass_UAttachmentsMenuButton_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAttachmentsMenuButton.OuterSingleton;
}
template<> WEAPONATTACHMENTS_API UClass* StaticClass<UAttachmentsMenuButton>()
{
	return UAttachmentsMenuButton::StaticClass();
}
UAttachmentsMenuButton::UAttachmentsMenuButton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAttachmentsMenuButton);
UAttachmentsMenuButton::~UAttachmentsMenuButton() {}
// End Class UAttachmentsMenuButton

// Begin Registration
struct Z_CompiledInDeferFile_FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_UI_AttachmentsMenuButton_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAttachmentsMenuButton, UAttachmentsMenuButton::StaticClass, TEXT("UAttachmentsMenuButton"), &Z_Registration_Info_UClass_UAttachmentsMenuButton, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAttachmentsMenuButton), 1637830303U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_UI_AttachmentsMenuButton_h_3156875636(TEXT("/Script/WeaponAttachments"),
	Z_CompiledInDeferFile_FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_UI_AttachmentsMenuButton_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_UI_AttachmentsMenuButton_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
