#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AttachmentsPanel.generated.h"

enum class EAttachmentModuleTypes : uint8;

UCLASS()
class WEAPONATTACHMENTS_API UAttachmentsPanel : public UUserWidget
{
    GENERATED_BODY()

    UPROPERTY()
    TObjectPtr<class UWeaponAttachmentsManager> attachmentsManagerRef;

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
    EAttachmentModuleTypes SlotType;

protected:
    UPROPERTY(meta = (BindWidget))
    TObjectPtr<class UTextBlock> panelLabel;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<class UVerticalBox> attachmentsList;

    UPROPERTY(EditDefaultsOnly, Category = MenuConfig)
    TSubclassOf<class UAttachmentsMenuButton> slotButtonTemplate;
};