// King's Gambit by Jonathan Mui and Kishor Kumar


#include "GuessModeUserWidget.h"
#include "TrainerController.h"
#include "Components/Button.h"
#include "Components/Border.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/CanvasPanel.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UGuessModeUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	//Gets Trainer Controller
	TrainerController = Cast<ATrainerController>(UGameplayStatics::GetPlayerController(this, 0));

	PauseButton->OnClicked.AddUniqueDynamic(this, &UGuessModeUserWidget::PauseButtonClicked);
	ResumeButton->OnClicked.AddUniqueDynamic(this, &UGuessModeUserWidget::ResumeButtonClicked);
	MainMenuButton->OnClicked.AddUniqueDynamic(this, &UGuessModeUserWidget::MainMenuButtonClicked);
	QuitButton->OnClicked.AddUniqueDynamic(this, &UGuessModeUserWidget::QuitButtonClicked);
	OKToMovesMode->OnClicked.AddUniqueDynamic(this, &UGuessModeUserWidget::OKToMovesModeClicked);
}

void UGuessModeUserWidget::PauseButtonClicked()
{
	Super::PauseButtonClicked();

	GuessModeHUD->SetVisibility(ESlateVisibility::Hidden);
}

void UGuessModeUserWidget::ResumeButtonClicked()
{
	Super::ResumeButtonClicked();

	GuessModeHUD->SetVisibility(ESlateVisibility::Visible);
}

void UGuessModeUserWidget::MainMenuButtonClicked()
{
	Super::MainMenuButtonClicked();
}

void UGuessModeUserWidget::QuitButtonClicked()
{
	Super::QuitButtonClicked();
}

void UGuessModeUserWidget::OKToMovesModeClicked()
{
	UGameplayStatics::SetGamePaused(GetWorld(), false);
	UserGuide_1->SetVisibility(ESlateVisibility::Hidden);

	GuessModeHUD->SetVisibility(ESlateVisibility::Visible);
	ManualButton->SetVisibility(ESlateVisibility::Visible);
}


