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

public:
    virtual void NativeConstruct() override;
    virtual void UpdateMenu();

    UFUNCTION(BlueprintCallable)
    void SetAttachmentsManager(class UWeaponAttachmentsManager *manager) { attachmentsComponentRef = manager; }

protected:
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<class UVerticalBox> slotsList;
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<class UOverlay> panelsContainer;

protected:
    UPROPERTY(EditDefaultsOnly, Category = MenuConfig)
    TSubclassOf<class UAttachmentsMenuButton> slotButtonTemplate;
    UPROPERTY(EditDefaultsOnly, Category = MenuConfig)
    TSubclassOf<class UAttachmentsPanel> panelTemplate;

protected:
    UFUNCTION()
    virtual void TogglePanel(class UAttachmentsMenuButton *slotButton);
};