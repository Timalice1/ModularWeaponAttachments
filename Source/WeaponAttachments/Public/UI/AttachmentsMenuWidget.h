#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AttachmentsMenuWidget.generated.h"

UCLASS()
class WEAPONATTACHMENTS_API UAttachmentsMenuWidget : public UUserWidget
{
    GENERATED_BODY()

private:
    UPROPERTY() /*Attachments manager reference*/
    TObjectPtr<class UWeaponAttachmentsManager> attachmentsComponentRef;
    UPROPERTY() /*Slot widget components instances array*/
    TArray<TObjectPtr<class UWidgetComponent>> slotWidget_Components;
    UPROPERTY() /*Slot widgets array*/
    TArray<TObjectPtr<class USlotWidget>> activeSlotWidgets;

    virtual void ClearSlotsWidgets();

public:
    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;

    UFUNCTION() /*Regenerate attachments menu and all widgets*/
    virtual void UpdateMenu();

    UFUNCTION(BlueprintCallable)
    void SetAttachmentsManager(class UWeaponAttachmentsManager *manager) { attachmentsComponentRef = manager; }

protected:
    UPROPERTY(EditDefaultsOnly, Category = MenuConfig)
    TSubclassOf<class USlotWidget> SlotWidgetTemplate;

protected:
    UFUNCTION()
    virtual void OnMenuOpened(class USlotWidget *slotWidget);
    UFUNCTION()
    virtual void OnModuleSelectionChanged(FName Item);
};