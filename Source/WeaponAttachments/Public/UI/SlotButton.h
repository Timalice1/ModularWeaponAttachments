#pragma once

#include "AttachmentsMenuButton.h"
#include "SlotButton.generated.h"

UCLASS()
class WEAPONATTACHMENTS_API USlotButton : public UAttachmentsMenuButton
{
    GENERATED_BODY()

public:
    virtual void SetVisible(bool bVisible = true);

public:
    UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
    TObjectPtr<class UImage> slotMarker;

    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = SlotButton)
    FVector2D pivotPoint = FVector2D(.5, .5);
};