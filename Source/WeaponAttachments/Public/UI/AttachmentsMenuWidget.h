#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AttachmentsMenuWidget.generated.h"

UCLASS()
class WEAPONATTACHMENTS_API UAttachmentsMenuWidget : public UUserWidget
{
    GENERATED_BODY()

private:
    UPROPERTY()
    TObjectPtr<class UWeaponAttachmentsManager> attachmentsComponentRef;
    UPROPERTY()
    TMap<class UAttachmentsMenuButton *, class UAttachmentsPanel *> _buttonToPanelMap;
    UPROPERTY()
    class UAttachmentsPanel *currentActivePanel = nullptr;
    UPROPERTY()
    TArray<TObjectPtr<class UWidgetComponent>> slotWidgets;
    UPROPERTY()
    TArray<TObjectPtr<class USlotButton>> slotButtons;

    virtual void ClearSlotsWidgets();

public:
    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;
    UFUNCTION()
    virtual void UpdateMenu();

    UFUNCTION(BlueprintCallable)
    void SetAttachmentsManager(class UWeaponAttachmentsManager *manager) { attachmentsComponentRef = manager; }

protected:
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<class UOverlay> panelsContainer;

    UPROPERTY(EditDefaultsOnly, Category = MenuConfig)
    TSubclassOf<class USlotButton> slotButtonTemplate;
    UPROPERTY(EditDefaultsOnly, Category = MenuConfig)
    TSubclassOf<class UAttachmentsPanel> panelTemplate;

protected:
    UFUNCTION()
    virtual void TogglePanel(class UAttachmentsMenuButton *slotButton);
};