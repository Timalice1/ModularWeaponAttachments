// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UI/AttachmentsMenuButton.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAttachmentsMenuButton;
#ifdef WEAPONATTACHMENTS_AttachmentsMenuButton_generated_h
#error "AttachmentsMenuButton.generated.h already included, missing '#pragma once' in AttachmentsMenuButton.h"
#endif
#define WEAPONATTACHMENTS_AttachmentsMenuButton_generated_h

#define FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_UI_AttachmentsMenuButton_h_7_DELEGATE \
WEAPONATTACHMENTS_API void FOnClickedSignature_DelegateWrapper(const FMulticastScriptDelegate& OnClickedSignature, UAttachmentsMenuButton* clickedButton);


#define FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_UI_AttachmentsMenuButton_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnButtonClicked);


#define FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_UI_AttachmentsMenuButton_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAttachmentsMenuButton(); \
	friend struct Z_Construct_UClass_UAttachmentsMenuButton_Statics; \
public: \
	DECLARE_CLASS(UAttachmentsMenuButton, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/WeaponAttachments"), NO_API) \
	DECLARE_SERIALIZER(UAttachmentsMenuButton)


#define FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_UI_AttachmentsMenuButton_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAttachmentsMenuButton(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UAttachmentsMenuButton(UAttachmentsMenuButton&&); \
	UAttachmentsMenuButton(const UAttachmentsMenuButton&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAttachmentsMenuButton); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAttachmentsMenuButton); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAttachmentsMenuButton) \
	NO_API virtual ~UAttachmentsMenuButton();


#define FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_UI_AttachmentsMenuButton_h_9_PROLOG
#define FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_UI_AttachmentsMenuButton_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_UI_AttachmentsMenuButton_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_UI_AttachmentsMenuButton_h_12_INCLASS_NO_PURE_DECLS \
	FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_UI_AttachmentsMenuButton_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> WEAPONATTACHMENTS_API UClass* StaticClass<class UAttachmentsMenuButton>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_UI_AttachmentsMenuButton_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
