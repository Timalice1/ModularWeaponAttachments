#pragma once

#include "CoreMinimal.h"
#include "AttachmentSlot.h"
#include "Attachment.generated.h"

enum class EAttachmentModuleTypes : uint8;

USTRUCT()
struct FAttachmentModuleData : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = BaseModuleParam)
    class UStaticMesh *Mesh;

    UPROPERTY(EditDefaultsOnly, Category = BaseModuleParam)
    EAttachmentModuleTypes ModuleType;  

    /*Child attachment slots*/
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = BaseModuleParam)
    TSet<FAttachmentSlot> childSlots;

    // Override base weapon property by attachment modifiers
    virtual void OverrideWeaponData(struct FFireWeaponProperties &weaponData) {};

    friend uint32 GetTypeHash(const FAttachmentModuleData &Other)
    {
        return FCrc::MemCrc32(&Other, sizeof(FAttachmentModuleData));
    }
};

/*
UCLASS(BlueprintType)
class WEAPONATTACHMENTS_API UAttachmentModule : public UStaticMeshComponent
{
    GENERATED_BODY()

public:
    FAttachmentModuleData moduleData;

public:
    UAttachmentModule()
    {
        PrimaryComponentTick.bCanEverTick = false;
        PrimaryComponentTick.bStartWithTickEnabled = false;
    };
    virtual void BeginPlay() override {};
    virtual FAttachmentModuleData GetModuleData() { return moduleData; };
};
*/