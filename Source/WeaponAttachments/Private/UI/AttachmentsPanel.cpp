#include "UI/AttachmentsPanel.h"
#include "UI/AttachmentsMenuButton.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"

void UAttachmentsPanel::NativeConstruct()
{
    Super::NativeConstruct();

    panelLabel->SetText(panelLabel_Text);
}