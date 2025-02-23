#include "UI/AttachmentsPanel.h"
#include "UI/AttachmentsMenuButton.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "WeaponAttachmentsManager.h"
#include "Attachment.h"

void UAttachmentsPanel::NativeConstruct()
{
    Super::NativeConstruct();
    panelLabel->SetText(panelLabel_Text);
}

void UAttachmentsPanel::UpdatePanel()
{
    if (!IsValid(attachmentsManagerRef))
    {
        UE_LOG(LogTemp, Warning, TEXT("AttachmentPanel widget - invalid reference to attachments manager component"));
        return;
    }

    if (!IsValid(slotButtonTemplate))
    {
        UE_LOG(LogTemp, Warning, TEXT("AttachmentPanel widget - missing reference to button template"));
        return;
    }

    attachmentsList->ClearChildren();

    TArray<FAttachmentModuleData> compatibleAttachments = attachmentsManagerRef->GetCompatibleAttachmentsByType(SlotType);
    for (FAttachmentModuleData &attachmentModule : compatibleAttachments)
    {
        UAttachmentsMenuButton *newAttachmentButton = NewObject<UAttachmentsMenuButton>(this, slotButtonTemplate);
        if (!newAttachmentButton)
        {
            UE_LOG(LogTemp, Warning, TEXT("Attachment panel widget - cannot instantiate new button"));
            continue;
        }
        newAttachmentButton->buttonLabelText = FText::FromName(attachmentModule.DisplayName);
        attachmentsList->AddChild(newAttachmentButton);
    }
}