#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AttachmentSlot.h"
#include "SlotWidget.generated.h"

UCLASS()
class WEAPONATTACHMENTS_API USlotWidget : public UUserWidget
{
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOpenedEvent, class USlotWidget *, slotWidget);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSelectionChangedEvent, FName, Item);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClosingEvent);

private:
    UPROPERTY()
    TObjectPtr<class UWeaponAttachmentsManager> attachmentsManager;

    FAttachmentSlot slotData;
    TArray<struct FAttachmentModuleData> compatibleAttachments;

    UFUNCTION()
    void HandleSelectionChanged(FName SelectedItem, ESelectInfo::Type SelectionType);

    UFUNCTION()
    virtual void HandleOpening();
    UFUNCTION()
    virtual void HandleClosing();

public:
    virtual void NativePreConstruct() override;
    virtual void NativeConstruct() override;

    virtual void SetVisible(bool bVisible = true);

    virtual void SetAttachmentsManager(class UWeaponAttachmentsManager *inManager);
    virtual void SetSlotData(FAttachmentSlot inSlotData);

    UPROPERTY(BlueprintCallable, Category = SlotWidget)
    FOnOpenedEvent OnOpened;
    UPROPERTY(BlueprintCallable, Category = SlotWidget)
    FOnClosingEvent OnClosed;
    UPROPERTY(BlueprintCallable, Category = SlotWidget)
    FOnSelectionChangedEvent OnSelectionChanged;

    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = SlotWidget)
    FVector2D pivotPoint = FVector2D(.5, .5);

protected: // Widgets
    UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
    TObjectPtr<class UImage> slotMarker;
    UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
    TObjectPtr<class UDropDown> modulesList;
};