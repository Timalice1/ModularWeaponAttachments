#include "UI/AttachmentsPanel.h"
#include "UI/AttachmentsMenuButton.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "WeaponAttachmentsManager.h"

void UAttachmentsPanel::NativeConstruct()
{
    Super::NativeConstruct();
    panelLabel->SetText(panelLabel_Text);
}

void UAttachmentsPanel::UpdatePanel()
{
    if (!IsValid(attachmentsManagerRef))
        return;

    if(!IsValid(slotButtonTemplate))
        return;

}