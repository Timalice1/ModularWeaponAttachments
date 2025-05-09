#pragma once

#include "CoreMinimal.h"
#include "AttachmentSlot.h"
#include "Attachment.generated.h"

USTRUCT()
struct FAttachmentModuleData : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, Category = BaseModule)
    FName DisplayName;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = BaseModule)
    class UStaticMesh *Mesh;

    UPROPERTY(EditDefaultsOnly, Category = BaseModule)
    uint8 ModuleType;

    /*Child attachment slots*/
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = BaseModule)
    TSet<FAttachmentSlot> childSlots;

    friend uint32 GetTypeHash(const FAttachmentModuleData &Other)
    {
        return FCrc::MemCrc32(&Other, sizeof(FAttachmentModuleData));
    }

    inline bool operator==(const FAttachmentModuleData &Other) const
    {
        return DisplayName == Other.DisplayName;
    }
};

UCLASS()
class WEAPONATTACHMENTS_API UAttachmentModuleComponent : public UStaticMeshComponent
{
    GENERATED_BODY()

public:
    UAttachmentModuleComponent()
    {
        PrimaryComponentTick.bCanEverTick = false;
        PrimaryComponentTick.bStartWithTickEnabled = false;
    }

    UPROPERTY()
    FAttachmentModuleData moduleData;
};