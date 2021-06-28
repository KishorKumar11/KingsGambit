// King's Gambit by Jonathan Mui and Kishor Kumar


#include "MainMenuUserWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/VerticalBox.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

//Acts like a beginplay for widgets
void UMainMenuUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	PlayButton->OnClicked.AddUniqueDynamic(this, &UMainMenuUserWidget::PlayButtonClicked);
	TrainerButton->OnClicked.AddUniqueDynamic(this, &UMainMenuUserWidget::TrainerButtonClicked);
	QuitButton->OnClicked.AddUniqueDynamic(this, &UMainMenuUserWidget::QuitButtonClicked);
	MainMenuButton->OnClicked.AddUniqueDynamic(this, &UMainMenuUserWidget::MainMenuButtonClicked);
	GuessButton->OnClicked.AddUniqueDynamic(this, &UMainMenuUserWidget::GuessButtonClicked);
	//SettingsButton->OnClicked.AddUniqueDynamic(this, &UMainMenuUserWidget::SettingsButtonClicked);
	//CreditsButton->OnClicked.AddUniqueDynamic(this, &UMainMenuUserWidget::CreditsButtonClicked);

	MovesButton->OnClicked.AddUniqueDynamic(this, &UMainMenuUserWidget::MovesClicked);
	NotationsButton->OnClicked.AddUniqueDynamic(this, &UMainMenuUserWidget::NotationsClicked);

	QueensGambitButton->OnClicked.AddUniqueDynamic(this, &UMainMenuUserWidget::QueensGambitButtonClicked);
	LondonSystemButton->OnClicked.AddUniqueDynamic(this, &UMainMenuUserWidget::LondonSystemButtonClicked);
	ItalianGameButton->OnClicked.AddUniqueDynamic(this, &UMainMenuUserWidget::ItalianGameButtonClicked);
	SicilianDefenceButton->OnClicked.AddUniqueDynamic(this, &UMainMenuUserWidget::SicilianDefenceButtonClicked);
	KingsIndianDefenceButton->OnClicked.AddUniqueDynamic(this, &UMainMenuUserWidget::KingsIndianDefenceButtonClicked);
	RuyLopezButton->OnClicked.AddUniqueDynamic(this, &UMainMenuUserWidget::RuyLopezButtonClicked);
}

void UMainMenuUserWidget::PlayButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), "Board1");
	RemoveFromParent();
}

void UMainMenuUserWidget::TrainerButtonClicked()
{
	MainMenu->SetVisibility(ESlateVisibility::Hidden);
	KingsGambitTitle->SetVisibility(ESlateVisibility::Hidden);
	TrainerMenu->SetVisibility(ESlateVisibility::Visible);
}

void UMainMenuUserWidget::QuitButtonClicked()
{
	UKismetSystemLibrary::ExecuteConsoleCommand(GetWorld(), "quit");
}

void UMainMenuUserWidget::GuessButtonClicked()
{
	MainMenu->SetVisibility(ESlateVisibility::Hidden);
	KingsGambitTitle->SetVisibility(ESlateVisibility::Hidden);
	OptionsPanel->SetVisibility(ESlateVisibility::Visible);
}

void UMainMenuUserWidget::NotationsClicked()
{
	MainMenu->SetVisibility(ESlateVisibility::Hidden);
	KingsGambitTitle->SetVisibility(ESlateVisibility::Hidden);
	OptionsPanel->SetVisibility(ESlateVisibility::Hidden);

	UGameplayStatics::OpenLevel(GetWorld(), "GuessModeBoard1");
	RemoveFromParent();
}

void UMainMenuUserWidget::MovesClicked()
{
	MainMenu->SetVisibility(ESlateVisibility::Hidden);
	KingsGambitTitle->SetVisibility(ESlateVisibility::Hidden);
	OptionsPanel->SetVisibility(ESlateVisibility::Hidden);

	UGameplayStatics::OpenLevel(GetWorld(), "GuessModeBoard");
	RemoveFromParent();
}

//void UMainMenuUserWidget::SettingsButtonClicked()
//{
//
//}
//
//void UMainMenuUserWidget::CreditsButtonClicked()
//{
//
//}

void UMainMenuUserWidget::MainMenuButtonClicked()
{
	MainMenu->SetVisibility(ESlateVisibility::Visible);
	KingsGambitTitle->SetVisibility(ESlateVisibility::Visible);
	TrainerMenu->SetVisibility(ESlateVisibility::Hidden);
}

void UMainMenuUserWidget::QueensGambitButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), "QueensGambitBoard");
	RemoveFromParent();
}

void UMainMenuUserWidget::LondonSystemButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), "LondonSystemBoard");
	RemoveFromParent();
}

void UMainMenuUserWidget::ItalianGameButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), "ItalianGameBoard");
	RemoveFromParent();
}

void UMainMenuUserWidget::SicilianDefenceButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), "SicilianDefenceBoard");
	RemoveFromParent();
}

void UMainMenuUserWidget::KingsIndianDefenceButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), "KingsIndianDefenceBoard");
	RemoveFromParent();
}

void UMainMenuUserWidget::RuyLopezButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), "RuyLopezBoard");
	RemoveFromParent();
}

