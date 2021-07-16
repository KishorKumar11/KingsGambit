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

	SetLevel(1);
}

void UGuessModeUserWidget::SetLevel(int32 level)
{
	switch (level) {
	case 1:
		TrainerController->ResetAllPieces();

		TrainerController->Move(TrainerController->WhitePawns[4], FVector(1200.f, 1600.f, 0.5f));

		Lvl1->SetVisibility(ESlateVisibility::Visible);

		break;

	case 2:
		//Reset pieces moved from lvl 1
		TrainerController->ResetAllPieces();

		break;

	case 3:
		//Reset Pieces moved from lvl 2
		TrainerController->ResetAllPieces();

		break;

	case 4:
		//Reset Pieces moved from lvl 3
		TrainerController->ResetAllPieces();

		break;

	case 5:
		TrainerController->ResetAllPieces();

		break;

	default:
		return;
	}
}


