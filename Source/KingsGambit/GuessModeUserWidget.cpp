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

	ManualButton->OnClicked.AddUniqueDynamic(this, &UGuessModeUserWidget::ManualButtonClicked);
	OKToMovesMode_1->OnClicked.AddUniqueDynamic(this, &UGuessModeUserWidget::OKToMovesMode1Clicked);

	GameOverToMenu->OnClicked.AddUniqueDynamic(this, &UGuessModeUserWidget::MainMenuButtonClicked);
	YouWonToMenu_1->OnClicked.AddUniqueDynamic(this, &UGuessModeUserWidget::MainMenuButtonClicked);
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

void UGuessModeUserWidget::OKToMovesMode1Clicked()
{
	UGameplayStatics::SetGamePaused(GetWorld(), false);

	ManualButton->SetVisibility(ESlateVisibility::Visible);
	PauseButton->SetVisibility(ESlateVisibility::Visible);
	GuessModeHUD->SetVisibility(ESlateVisibility::Visible);

	UserGuide_2->SetVisibility(ESlateVisibility::Hidden);
}

void UGuessModeUserWidget::ManualButtonClicked()
{
	UGameplayStatics::SetGamePaused(GetWorld(), true);

	ManualButton->SetVisibility(ESlateVisibility::Hidden);
	PauseButton->SetVisibility(ESlateVisibility::Hidden);
	GuessModeHUD->SetVisibility(ESlateVisibility::Hidden);

	UserGuide_2->SetVisibility(ESlateVisibility::Visible);
}

void UGuessModeUserWidget::ResetLevels()
{
	Lvl1->SetVisibility(ESlateVisibility::Visible);
	Lvl2->SetVisibility(ESlateVisibility::Hidden);
	Lvl3->SetVisibility(ESlateVisibility::Hidden);
	Lvl4->SetVisibility(ESlateVisibility::Hidden);
	Lvl5->SetVisibility(ESlateVisibility::Hidden);
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

		TrainerController->Move(TrainerController->WhitePawns[3], FVector(1200.f, 1200.f, 0.5f));
		TrainerController->Move(TrainerController->BlackPawns[3], FVector(1600.f, 1200.f, 0.5f));

		Lvl1->SetVisibility(ESlateVisibility::Hidden);
		Lvl2->SetVisibility(ESlateVisibility::Visible);

		break;

	case 3:
		//Reset Pieces moved from lvl 2
		TrainerController->ResetAllPieces();

		TrainerController->Move(TrainerController->WhitePawns[4], FVector(1200.f, 1600.f, 0.5f));
		TrainerController->Move(TrainerController->BlackPawns[4], FVector(1600.f, 1600.f, 0.5f));
		TrainerController->Move(TrainerController->WhiteKnights[1], FVector(800.f, 2000.f, 0.5f));
		TrainerController->Move(TrainerController->BlackKnights[0], FVector(2000.f, 800.f, 0.5f));

		Lvl2->SetVisibility(ESlateVisibility::Hidden);
		Lvl3->SetVisibility(ESlateVisibility::Visible);

		break;

	case 4:
		//Reset Pieces moved from lvl 3
		TrainerController->ResetAllPieces();

		TrainerController->Move(TrainerController->WhitePawns[3], FVector(1200.f, 1200.f, 0.5f));
		TrainerController->Move(TrainerController->WhitePawns[2], FVector(1200.f, 800.f, 0.5f));
		TrainerController->Move(TrainerController->BlackKnights[1], FVector(2000.f, 2000.f, 0.5f));

		Lvl3->SetVisibility(ESlateVisibility::Hidden);
		Lvl4->SetVisibility(ESlateVisibility::Visible);

		break;

	case 5:
		TrainerController->ResetAllPieces();

		TrainerController->Move(TrainerController->WhitePawns[4], FVector(1200.f, 1600.f, 0.5f));
		TrainerController->Move(TrainerController->BlackPawns[4], FVector(1600.f, 1600.f, 0.5f));
		TrainerController->Move(TrainerController->WhiteKnights[1], FVector(800.f, 2000.f, 0.5f));
		TrainerController->Move(TrainerController->BlackKnights[0], FVector(2000.f, 800.f, 0.5f));

		Lvl4->SetVisibility(ESlateVisibility::Hidden);
		Lvl5->SetVisibility(ESlateVisibility::Visible);

		break;

	default:
		return;
	}
}


