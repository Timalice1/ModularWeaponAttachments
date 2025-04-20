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

    if (!IsValid(attachmentButtonTemplate))
    {
        UE_LOG(LogTemp, Warning, TEXT("AttachmentPanel widget - missing reference to button template"));
        return;
    }

    attachmentsList->ClearChildren();

    TArray<FAttachmentModuleData> compatibleAttachments = attachmentsManagerRef->GetCompatibleAttachmentsByType(slotData.slotType);
    for (FAttachmentModuleData &attachmentModule : compatibleAttachments)
    {
        UAttachmentsMenuButton *newAttachmentButton = NewObject<UAttachmentsMenuButton>(this, attachmentButtonTemplate);
        if (!newAttachmentButton)
        {
            UE_LOG(LogTemp, Warning, TEXT("Attachment panel widget - cannot instantiate new button"));
            continue;
        }
        newAttachmentButton->buttonLabelText = FText::FromName(attachmentModule.DisplayName);
        attachmentsList->AddChild(newAttachmentButton);
        _buttonToModuleMap.Add(newAttachmentButton, attachmentModule);
        newAttachmentButton->OnClick.AddDynamic(this, &ThisClass::OnAttachmentButtonClicked);
    }
}

void UAttachmentsPanel::OnAttachmentButtonClicked(UAttachmentsMenuButton *button)
{
    FAttachmentModuleData *targetModule = _buttonToModuleMap.Find(button);
    if (!targetModule)
    {
        UE_LOG(LogTemp, Warning, TEXT("[%s] - Required module not found"), *GetName());
        return;
    }
    attachmentsManagerRef->InstallModule(slotData.SlotName, *targetModule);
    OnModuleInstalled.Broadcast();
}