// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "WeaponAttachmentsManager.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UMeshComponent;
struct FAttachmentModuleData;
struct FAttachmentSlot;
#ifdef WEAPONATTACHMENTS_WeaponAttachmentsManager_generated_h
#error "WeaponAttachmentsManager.generated.h already included, missing '#pragma once' in WeaponAttachmentsManager.h"
#endif
#define WEAPONATTACHMENTS_WeaponAttachmentsManager_generated_h

#define FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_WeaponAttachmentsManager_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execRemoveModule); \
	DECLARE_FUNCTION(execInstallModule); \
	DECLARE_FUNCTION(execGetActiveSlots); \
	DECLARE_FUNCTION(execSetBaseWeaponMeshComponent);


#define FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_WeaponAttachmentsManager_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUWeaponAttachmentsManager(); \
	friend struct Z_Construct_UClass_UWeaponAttachmentsManager_Statics; \
public: \
	DECLARE_CLASS(UWeaponAttachmentsManager, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/WeaponAttachments"), NO_API) \
	DECLARE_SERIALIZER(UWeaponAttachmentsManager)


#define FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_WeaponAttachmentsManager_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UWeaponAttachmentsManager(UWeaponAttachmentsManager&&); \
	UWeaponAttachmentsManager(const UWeaponAttachmentsManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UWeaponAttachmentsManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UWeaponAttachmentsManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UWeaponAttachmentsManager) \
	NO_API virtual ~UWeaponAttachmentsManager();


#define FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_WeaponAttachmentsManager_h_9_PROLOG
#define FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_WeaponAttachmentsManager_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_WeaponAttachmentsManager_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_WeaponAttachmentsManager_h_12_INCLASS_NO_PURE_DECLS \
	FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_WeaponAttachmentsManager_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> WEAPONATTACHMENTS_API UClass* StaticClass<class UWeaponAttachmentsManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Work_Unreal_Projects_SRPGw_Plugins_WeaponAttachments_Source_WeaponAttachments_Public_WeaponAttachmentsManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
