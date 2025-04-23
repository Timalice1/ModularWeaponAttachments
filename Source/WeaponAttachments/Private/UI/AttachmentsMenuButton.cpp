#include "UI/AttachmentsMenuButton.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

void UAttachmentsMenuButton::NativePreConstruct()
{
    Super::NativePreConstruct();
    buttonLabel->SetText(buttonLabelText);
    button->IsFocusable = false;
    button->OnClicked.AddDynamic(this, &ThisClass::OnButtonClicked);
}

void UAttachmentsMenuButton::NativeConstruct()
{
    Super::NativeConstruct();
}

void UAttachmentsMenuButton::OnButtonClicked()
{
    OnClick.Broadcast(this);
}