#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Attachment.h"
#include "AttachmentsPanel.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnModuleInstalledSignature);

UCLASS()
class WEAPONATTACHMENTS_API UAttachmentsPanel : public UUserWidget
{
    GENERATED_BODY()

    UPROPERTY()
    TObjectPtr<class UWeaponAttachmentsManager> attachmentsManagerRef;
    UPROPERTY()
    TMap<class UAttachmentsMenuButton *, FAttachmentModuleData> _buttonToModuleMap;

public:
    virtual void NativeConstruct() override;

    UPROPERTY(EditDefaultsOnly, Category = PanelConfig)
    FText panelLabel_Text = FText::FromString("AttachmentsPanel");

    virtual void SetAttachmentsManager(class UWeaponAttachmentsManager *manager)
    {
        attachmentsManagerRef = manager;
    }

    virtual void UpdatePanel();

    UPROPERTY()
    FAttachmentSlot slotData;

    UPROPERTY(BlueprintAssignable)
    FOnModuleInstalledSignature OnModuleInstalled;

protected:
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<class UTextBlock> panelLabel;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<class UVerticalBox> attachmentsList;

    UPROPERTY(EditDefaultsOnly, Category = MenuConfig)
    TSubclassOf<class UAttachmentsMenuButton> slotButtonTemplate;

protected:
    UFUNCTION()
    void OnAttachmentButtonClicked(class UAttachmentsMenuButton *button);
};