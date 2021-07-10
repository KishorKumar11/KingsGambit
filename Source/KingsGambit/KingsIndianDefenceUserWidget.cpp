// King's Gambit by Jonathan Mui and Kishor Kumar


#include "KingsIndianDefenceUserWidget.h"
#include "TrainerController.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/CanvasPanel.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UKingsIndianDefenceUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	//Gets Trainer Controller
	TrainerController = Cast<ATrainerController>(UGameplayStatics::GetPlayerController(this, 0));

	PauseButton->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::PauseButtonClicked);
	ResumeButton->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::ResumeButtonClicked);
	MainMenuButton->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::MainMenuButtonClicked);
	QuitButton->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::QuitButtonClicked);
	StepZeroToOne->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepZeroToOneClicked);
	StepOneToZero->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepOneToZeroClicked);
	StepOneToTwo->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepOneToTwoClicked);
	StepTwoToOne->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepTwoToOneClicked);
	StepTwoToThree->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepTwoToThreeClicked);
	StepThreeToTwo->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::StepThreeToTwoClicked);
	StepThreeToMainMenu->OnClicked.AddUniqueDynamic(this, &UKingsIndianDefenceUserWidget::MainMenuButtonClicked);
}

void UKingsIndianDefenceUserWidget::PauseButtonClicked()
{
	Super::PauseButtonClicked();

	ExplanationPanel->SetVisibility(ESlateVisibility::Hidden);
}

void UKingsIndianDefenceUserWidget::ResumeButtonClicked()
{
	Super::ResumeButtonClicked();

	ExplanationPanel->SetVisibility(ESlateVisibility::Visible);
}

void UKingsIndianDefenceUserWidget::MainMenuButtonClicked()
{
	Super::MainMenuButtonClicked();
}

void UKingsIndianDefenceUserWidget::QuitButtonClicked()
{
	Super::QuitButtonClicked();
}

void UKingsIndianDefenceUserWidget::StepZeroToOneClicked()
{
	StepZeroToOne->SetVisibility(ESlateVisibility::Hidden);
	StepZeroTxt->SetVisibility(ESlateVisibility::Hidden);
	StepOneToZero->SetVisibility(ESlateVisibility::Visible);
	StepOneToTwo->SetVisibility(ESlateVisibility::Visible);
	StepOneTxt->SetVisibility(ESlateVisibility::Visible);

	//White's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->WhitePawns[3], FVector(1200.f, 1200.f, 0.5f));
	//Black's King side Knight 
	TrainerController->Move(TrainerController->BlackKnights[1], FVector(2000.f, 2000.f, 0.5f));
}

void UKingsIndianDefenceUserWidget::StepOneToZeroClicked()
{
	StepZeroToOne->SetVisibility(ESlateVisibility::Visible);
	StepZeroTxt->SetVisibility(ESlateVisibility::Visible);
	StepOneToZero->SetVisibility(ESlateVisibility::Hidden);
	StepOneTxt->SetVisibility(ESlateVisibility::Hidden);

	//White's Pawn back to its original position
	TrainerController->Move(TrainerController->WhitePawns[3], TrainerController->WhitePawns[3]->OriginalSpawnLocation);
	//Black's Knight back to its original position
	TrainerController->Move(TrainerController->BlackKnights[1], TrainerController->BlackKnights[1]->OriginalSpawnLocation);
}

void UKingsIndianDefenceUserWidget::StepOneToTwoClicked()
{
	StepOneToTwo->SetVisibility(ESlateVisibility::Hidden);
	StepOneToZero->SetVisibility(ESlateVisibility::Hidden);
	StepOneTxt->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToOne->SetVisibility(ESlateVisibility::Visible);
	StepTwoToThree->SetVisibility(ESlateVisibility::Visible);
	StepTwoTxt->SetVisibility(ESlateVisibility::Visible);

	//White's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->WhitePawns[2], FVector(1200.f, 800.f, 0.5f));
	//Black's Pawn Moves 1 step forward
	TrainerController->Move(TrainerController->BlackPawns[6], FVector(2000.f, 2400.f, 0.5f));

}

void UKingsIndianDefenceUserWidget::StepTwoToOneClicked()
{
	StepOneToTwo->SetVisibility(ESlateVisibility::Visible);
	StepOneToZero->SetVisibility(ESlateVisibility::Visible);
	StepOneTxt->SetVisibility(ESlateVisibility::Visible);
	StepTwoToOne->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToThree->SetVisibility(ESlateVisibility::Hidden);
	StepTwoTxt->SetVisibility(ESlateVisibility::Hidden);

	//White's Pawn back to its original position
	TrainerController->Move(TrainerController->WhitePawns[2], TrainerController->WhitePawns[2]->OriginalSpawnLocation);
	//Black's Pawn back to its original position
	TrainerController->Move(TrainerController->BlackPawns[6], TrainerController->BlackPawns[6]->OriginalSpawnLocation);

}

void UKingsIndianDefenceUserWidget::StepTwoToThreeClicked()
{
	StepTwoToThree->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToOne->SetVisibility(ESlateVisibility::Hidden);
	StepTwoTxt->SetVisibility(ESlateVisibility::Hidden);
	StepThreeToMainMenu->SetVisibility(ESlateVisibility::Visible);
	StepThreeToTwo->SetVisibility(ESlateVisibility::Visible);
	StepThreeTxt->SetVisibility(ESlateVisibility::Visible);

	//White's Queen side Knight 
	TrainerController->Move(TrainerController->WhiteKnights[0], FVector(800.f, 800.f, 0.5f));
	//Black's King side Bishop Moves 1 step forward
	TrainerController->Move(TrainerController->BlackBishops[1], FVector(2400.f, 2400.f, 0.5f));
	//White's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->WhitePawns[4], FVector(1200.f, 1600.f, 0.5f));
	//Black's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->BlackPawns[3], FVector(2000.f, 1200.f, 0.5f));

}

void UKingsIndianDefenceUserWidget::StepThreeToTwoClicked()
{
	StepTwoToThree->SetVisibility(ESlateVisibility::Visible);
	StepTwoToOne->SetVisibility(ESlateVisibility::Visible);
	StepTwoTxt->SetVisibility(ESlateVisibility::Visible);
	StepThreeToTwo->SetVisibility(ESlateVisibility::Hidden);
	StepThreeTxt->SetVisibility(ESlateVisibility::Hidden);
	StepThreeToMainMenu->SetVisibility(ESlateVisibility::Hidden);

	//White's Knight back to its original position
	TrainerController->Move(TrainerController->WhiteKnights[0], TrainerController->WhiteKnights[0]->OriginalSpawnLocation);
	//Black's Pawn back to its original position
	TrainerController->Move(TrainerController->BlackBishops[1], TrainerController->BlackBishops[1]->OriginalSpawnLocation);
	//White's Pawn back to its original position
	TrainerController->Move(TrainerController->WhitePawns[4], TrainerController->WhitePawns[4]->OriginalSpawnLocation);
	//Black's Pawn back to its original position
	TrainerController->Move(TrainerController->WhitePawns[3], TrainerController->WhitePawns[3]->OriginalSpawnLocation);

}

void UKingsIndianDefenceUserWidget::StepThreeToSelect_VariationClicked()
{
}

void UKingsIndianDefenceUserWidget::StepSelectVariationToThreeClicked()
{
}

void UKingsIndianDefenceUserWidget::StepPVToSelectVariationClicked()
{
}

void UKingsIndianDefenceUserWidget::StepSVWP1Clicked()
{
}

void UKingsIndianDefenceUserWidget::StepSVWP1ToBackClicked()
{
}

void UKingsIndianDefenceUserWidget::StepSVWP2Clicked()
{
}

void UKingsIndianDefenceUserWidget::StepSVWP2ToBackClicked()
{
}

void UKingsIndianDefenceUserWidget::StepSVBP1Clicked()
{
}

void UKingsIndianDefenceUserWidget::StepSVBP1ToBackClicked()
{
}

void UKingsIndianDefenceUserWidget::StepSVBP2Clicked()
{
}

void UKingsIndianDefenceUserWidget::StepSVBP2ToBackClicked()
{
}

void UKingsIndianDefenceUserWidget::StepSVToSelectVariationClicked()
{
}

void UKingsIndianDefenceUserWidget::StepFPAWP1Clicked()
{
}

void UKingsIndianDefenceUserWidget::StepFPAWP1ToBackClicked()
{
}

void UKingsIndianDefenceUserWidget::StepFPAWP2Clicked()
{
}

void UKingsIndianDefenceUserWidget::StepFPAWP2ToBackClicked()
{
}

void UKingsIndianDefenceUserWidget::StepFPABP1Clicked()
{
}

void UKingsIndianDefenceUserWidget::StepFPABP1ToBackClicked()
{
}

void UKingsIndianDefenceUserWidget::StepFPABP2Clicked()
{
}

void UKingsIndianDefenceUserWidget::StepFPABP2ToBackClicked()
{
}

void UKingsIndianDefenceUserWidget::StepFPAToSelectVariationClicked()
{
}

void UKingsIndianDefenceUserWidget::StepPetrosianVariationClicked()
{
}

void UKingsIndianDefenceUserWidget::StepSamischVariationClicked()
{
}

void UKingsIndianDefenceUserWidget::StepFourPawnsAttackClicked()
{
}

void UKingsIndianDefenceUserWidget::StepPVWP1Clicked()
{
}

void UKingsIndianDefenceUserWidget::StepPVWP1ToBackClicked()
{
}

void UKingsIndianDefenceUserWidget::StepPVWP2Clicked()
{
}

void UKingsIndianDefenceUserWidget::StepPVWP2ToBackClicked()
{
}

void UKingsIndianDefenceUserWidget::StepPVBP1Clicked()
{
}

void UKingsIndianDefenceUserWidget::StepPVBP1ToBackClicked()
{
}

void UKingsIndianDefenceUserWidget::StepPVBP2Clicked()
{
}

void UKingsIndianDefenceUserWidget::StepPVBP2ToBackClicked()
{
}

