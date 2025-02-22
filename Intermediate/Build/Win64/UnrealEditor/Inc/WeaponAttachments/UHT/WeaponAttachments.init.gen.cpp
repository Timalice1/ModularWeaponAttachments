// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWeaponAttachments_init() {}
	WEAPONATTACHMENTS_API UFunction* Z_Construct_UDelegateFunction_WeaponAttachments_OnClickedSignature__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_WeaponAttachments;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_WeaponAttachments()
	{
		if (!Z_Registration_Info_UPackage__Script_WeaponAttachments.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_WeaponAttachments_OnClickedSignature__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/WeaponAttachments",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xE861EF98,
				0x1EE0AD5D,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_WeaponAttachments.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_WeaponAttachments.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_WeaponAttachments(Z_Construct_UPackage__Script_WeaponAttachments, TEXT("/Script/WeaponAttachments"), Z_Registration_Info_UPackage__Script_WeaponAttachments, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xE861EF98, 0x1EE0AD5D));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
