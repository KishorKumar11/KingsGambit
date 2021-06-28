// King's Gambit by Jonathan Mui and Kishor Kumar


#include "PauseMenuUserWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/Border.h"
#include "Components/VerticalBox.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

//Acts like a beginplay for widgets
void UPauseMenuUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	PauseButton->OnClicked.AddUniqueDynamic(this, &UPauseMenuUserWidget::PauseButtonClicked);
	ResumeButton->OnClicked.AddUniqueDynamic(this, &UPauseMenuUserWidget::ResumeButtonClicked);
	MainMenuButton->OnClicked.AddUniqueDynamic(this, &UPauseMenuUserWidget::MainMenuButtonClicked);
	QuitButton->OnClicked.AddUniqueDynamic(this, &UPauseMenuUserWidget::QuitButtonClicked);
}

void UPauseMenuUserWidget::PauseButtonClicked()
{
	UGameplayStatics::SetGamePaused(GetWorld(), true);
	PauseButton->SetVisibility(ESlateVisibility::Hidden);
	PauseIcon->SetVisibility(ESlateVisibility::Hidden);
	PauseMenuInterface->SetVisibility(ESlateVisibility::Visible);
	PauseMenu->SetVisibility(ESlateVisibility::Visible);
}

void UPauseMenuUserWidget::ResumeButtonClicked()
{
	UGameplayStatics::SetGamePaused(GetWorld(), false);
	PauseButton->SetVisibility(ESlateVisibility::Visible);
	PauseIcon->SetVisibility(ESlateVisibility::Visible);
	PauseMenuInterface->SetVisibility(ESlateVisibility::Hidden);
	PauseMenu->SetVisibility(ESlateVisibility::Hidden);
}

void UPauseMenuUserWidget::MainMenuButtonClicked()
{
	RemoveFromParent();
	UGameplayStatics::OpenLevel(GetWorld(), "Menu");
}

void UPauseMenuUserWidget::QuitButtonClicked()
{
	UKismetSystemLibrary::ExecuteConsoleCommand(GetWorld(), "quit");
}
