// King's Gambit by Jonathan Mui and Kishor Kumar


#include "SicilianDefenceUserWidget.h"
#include "TrainerController.h"
#include "Components/Button.h"
#include "Components/VerticalBox.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/CanvasPanel.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void USicilianDefenceUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	//Gets Trainer Controller
	TrainerController = Cast<ATrainerController>(UGameplayStatics::GetPlayerController(this, 0));

	PauseButton->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::PauseButtonClicked);
	ResumeButton->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::ResumeButtonClicked);
	MainMenuButton->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::MainMenuButtonClicked);
	QuitButton->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::QuitButtonClicked);
	StepZeroToOne->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepZeroToOneClicked);
	StepOneToZero->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepOneToZeroClicked);
	StepOneToTwo->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepOneToTwoClicked);
	StepTwoToOne->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepTwoToOneClicked);
	StepTwoToThree->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepTwoToThreeClicked);
	StepThreeToTwo->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepThreeToTwoClicked);
	StepVariationToMainMenu->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::MainMenuButtonClicked);
	StepThreeToVariation->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepThreeToVariationClicked);

	//StepNVWP1->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepNVWP1Clicked);
	//StepNVWP1ToBack->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepNVWP1ToBackClicked);
	//StepNVWP2->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepNVWP2Clicked);
	//StepNVWP2ToBack->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepNVWP2ToBackClicked);
	//StepNVWP3->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepNVWP3Clicked);
	//StepNVWP3ToBack->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepNVWP3ToBackClicked);
	//StepNVBP1->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepNVBP1Clicked);
	//StepNVBP1ToBack->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepNVBP1ToBackClicked);
	//StepNVBP2->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepNVBP2Clicked);
	//StepNVBP2ToBack->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepNVBP2ToBackClicked);
	//StepNVBP3->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepNVBP3Clicked);
	//StepNVBP3ToBack->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepNVBP3ToBackClicked);
	//StepNVToSelectVariation->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepNVToSelectVariationClicked);

	//StepDVWP1->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepDVWP1Clicked);
	//StepDVWP1ToBack->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepDVWP1ToBackClicked);
	//StepDVWP2->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepDVWP2Clicked);
	//StepDVWP2ToBack->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepDVWP2ToBackClicked);
	//StepDVWP3->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepDVWP3Clicked);
	//StepDVWP3ToBack->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepADWP3ToBackClicked);
	//StepDVBP1->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepDVBP1Clicked);
	//StepDVBP1ToBack->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepDVBP1ToBackClicked);
	//StepDVBP2->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepDVBP2Clicked);
	//StepDVBP2ToBack->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepDVBP2ToBackClicked);
	//StepDVBP3->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepDVBP3Clicked);
	//StepDVBP3ToBack->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepDVBP3ToBackClicked);
	//StepDVBP4->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepDVBP4Clicked);
	//StepDVBP4ToBack->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepDVBP4ToBackClicked);
	//StepDVToSelectVariation->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::DVToSelectVariationClicked);

	//StepCVWP1->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepCVWP1Clicked);
	//StepCVWP1ToBack->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepCVWP1ToBackClicked);
	//StepCVWP2->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepCVWP2Clicked);
	//StepCVWP2ToBack->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepCVWP2ToBackClicked);
	//StepCVWP3->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepCVWP3Clicked);
	//StepCVWP3ToBack->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepCVWP3ToBackClicked);
	//StepCVWP4->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepCVWP4Clicked);
	//StepCVWP4ToBack->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepCVWP4ToBackClicked);
	//StepCVBP1->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepCVBP1Clicked);
	//StepCVBP1ToBack->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepCVBP1ToBackClicked);
	//StepCVBP2->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepCVBP2Clicked);
	//StepCVBP2ToBack->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepCVBP2ToBackClicked);
	//StepCVBP3->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepCVBP3Clicked);
	//StepCVBP3ToBack->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepCVBP3ToBackClicked);
	//StepCVBP4->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepCVBP4Clicked);
	//StepCVBP4ToBack->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepCVBP4ToBackClicked);
	//StepCVToSelectVariation->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::CVToSelectVariationClicked);
}

void USicilianDefenceUserWidget::PauseButtonClicked()
{
	Super::PauseButtonClicked();

	ExplanationPanel->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::ResumeButtonClicked()
{
	Super::ResumeButtonClicked();

	ExplanationPanel->SetVisibility(ESlateVisibility::Visible);
}

void USicilianDefenceUserWidget::MainMenuButtonClicked()
{
	Super::MainMenuButtonClicked();
}

void USicilianDefenceUserWidget::QuitButtonClicked()
{
	Super::QuitButtonClicked();
}

void USicilianDefenceUserWidget::StepZeroToOneClicked()
{
	StepZeroToOne->SetVisibility(ESlateVisibility::Hidden);
	StepZeroTxt->SetVisibility(ESlateVisibility::Hidden);
	StepOneToZero->SetVisibility(ESlateVisibility::Visible);
	StepOneToTwo->SetVisibility(ESlateVisibility::Visible);
	StepOneTxt->SetVisibility(ESlateVisibility::Visible);

	//White's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->WhitePawns[4], FVector(1200.f, 1600.f, 0.5f));
	//Black's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->BlackPawns[2], FVector(1600.f, 800.f, 0.5f));
}

void USicilianDefenceUserWidget::StepOneToZeroClicked()
{
	StepZeroToOne->SetVisibility(ESlateVisibility::Visible);
	StepZeroTxt->SetVisibility(ESlateVisibility::Visible);
	StepOneToZero->SetVisibility(ESlateVisibility::Hidden);
	StepOneTxt->SetVisibility(ESlateVisibility::Hidden);

	//White's Pawn back to its original position
	TrainerController->Move(TrainerController->WhitePawns[4], TrainerController->WhitePawns[4]->OriginalSpawnLocation);
	//Black's Pawn back to its original position
	TrainerController->Move(TrainerController->BlackPawns[2], TrainerController->BlackPawns[2]->OriginalSpawnLocation);
}

void USicilianDefenceUserWidget::StepOneToTwoClicked()
{
	StepOneToTwo->SetVisibility(ESlateVisibility::Hidden);
	StepOneToZero->SetVisibility(ESlateVisibility::Hidden);
	StepOneTxt->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToOne->SetVisibility(ESlateVisibility::Visible);
	StepTwoToThree->SetVisibility(ESlateVisibility::Visible);
	StepTwoTxt->SetVisibility(ESlateVisibility::Visible);

	//White's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->WhitePawns[3], FVector(1200.f, 1200.f, 0.5f));

}

void USicilianDefenceUserWidget::StepTwoToOneClicked()
{
	StepOneToTwo->SetVisibility(ESlateVisibility::Visible);
	StepOneToZero->SetVisibility(ESlateVisibility::Visible);
	StepOneTxt->SetVisibility(ESlateVisibility::Visible);
	StepTwoToOne->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToThree->SetVisibility(ESlateVisibility::Hidden);
	StepTwoTxt->SetVisibility(ESlateVisibility::Hidden);

	//White's Pawn back to its original position
	TrainerController->Move(TrainerController->WhitePawns[3], TrainerController->WhitePawns[3]->OriginalSpawnLocation);

}

void USicilianDefenceUserWidget::StepTwoToThreeClicked()
{
	StepTwoToThree->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToOne->SetVisibility(ESlateVisibility::Hidden);
	StepTwoTxt->SetVisibility(ESlateVisibility::Hidden);
	StepThreeToTwo->SetVisibility(ESlateVisibility::Visible);
	StepThreeTxt->SetVisibility(ESlateVisibility::Visible);
	StepThreeToVariation->SetVisibility(ESlateVisibility::Visible);

	//Black's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->BlackPawns[2], FVector(1200.f, 1200.f, 0.5f));
}

void USicilianDefenceUserWidget::StepThreeToTwoClicked()
{
	StepTwoToThree->SetVisibility(ESlateVisibility::Visible);
	StepTwoToOne->SetVisibility(ESlateVisibility::Visible);
	StepTwoTxt->SetVisibility(ESlateVisibility::Visible);
	StepThreeToTwo->SetVisibility(ESlateVisibility::Hidden);
	StepThreeTxt->SetVisibility(ESlateVisibility::Hidden);
	StepThreeToVariation->SetVisibility(ESlateVisibility::Hidden);

	//Black's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->BlackPawns[2], FVector(1600.f, 800.f, 0.5f));
}

void USicilianDefenceUserWidget::StepThreeToVariationClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Hidden);

	StepThreeToTwo->SetVisibility(ESlateVisibility::Hidden);
	StepThreeTxt->SetVisibility(ESlateVisibility::Hidden);
	StepThreeToVariation->SetVisibility(ESlateVisibility::Hidden);

	NajdorfVariation->SetVisibility(ESlateVisibility::Visible);
	DragonVariation->SetVisibility(ESlateVisibility::Visible);
	ClassicalVariation->SetVisibility(ESlateVisibility::Visible);
	StepSelectVariationToThree->SetVisibility(ESlateVisibility::Visible);
	StepVariationToMainMenu->SetVisibility(ESlateVisibility::Visible);
}

void USicilianDefenceUserWidget::StepSelectVariationToThreeClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Hidden);

	StepTwoToThree->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToOne->SetVisibility(ESlateVisibility::Hidden);
	StepTwoTxt->SetVisibility(ESlateVisibility::Hidden);
	StepThreeToVariation->SetVisibility(ESlateVisibility::Visible);
	StepThreeToTwo->SetVisibility(ESlateVisibility::Visible);
	StepThreeTxt->SetVisibility(ESlateVisibility::Visible);

	//Black's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->BlackPawns[2], FVector(1200.f, 1200.f, 0.5f));
}

void USicilianDefenceUserWidget::NajdorfVariationClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Visible);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Hidden);

	StepNVTxt->SetVisibility(ESlateVisibility::Visible);
	StepNV1Txt->SetVisibility(ESlateVisibility::Visible);
	StepNVWP1->SetVisibility(ESlateVisibility::Visible);
	StepNVWP1ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepNVWP2->SetVisibility(ESlateVisibility::Visible);
	StepNVWP2ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepNVWP3->SetVisibility(ESlateVisibility::Visible);
	StepNVWP3ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepNVBP1->SetVisibility(ESlateVisibility::Visible);
	StepNVBP1ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepNVBP2->SetVisibility(ESlateVisibility::Visible);
	StepNVBP2ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepNVBP3->SetVisibility(ESlateVisibility::Visible);
	StepNVBP3ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepNVToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	NV_Main->SetVisibility(ESlateVisibility::Visible);
	NV_WHITEMOVES->SetVisibility(ESlateVisibility::Visible);
	NV_BLACKMOVES->SetVisibility(ESlateVisibility::Visible);
}

void USicilianDefenceUserWidget::DragonVariationClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Visible);
	Classical->SetVisibility(ESlateVisibility::Hidden);

	StepDVTxt->SetVisibility(ESlateVisibility::Visible);
	StepDV1Txt->SetVisibility(ESlateVisibility::Visible);
	StepDVWP1->SetVisibility(ESlateVisibility::Visible);
	StepDVWP1ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepDVWP2->SetVisibility(ESlateVisibility::Visible);
	StepDVWP2ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepDVWP3->SetVisibility(ESlateVisibility::Visible);
	StepDVWP3ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepDVBP1->SetVisibility(ESlateVisibility::Visible);
	StepDVBP1ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepDVBP2->SetVisibility(ESlateVisibility::Visible);
	StepDVBP2ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepDVBP3->SetVisibility(ESlateVisibility::Visible);
	StepDVBP3ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepDVBP4->SetVisibility(ESlateVisibility::Visible);
	StepDVBP4ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepDVToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	DV_Main->SetVisibility(ESlateVisibility::Visible);
	DV_WHITEMOVES->SetVisibility(ESlateVisibility::Visible);
	DV_BLACKMOVES->SetVisibility(ESlateVisibility::Visible);
}

void USicilianDefenceUserWidget::ClassicalVariationClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Visible);

	StepCVTxt->SetVisibility(ESlateVisibility::Visible);
	StepCV1Txt->SetVisibility(ESlateVisibility::Visible);
	StepCVWP1->SetVisibility(ESlateVisibility::Visible);
	StepCVWP1ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepCVWP2->SetVisibility(ESlateVisibility::Visible);
	StepCVWP2ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepCVWP3->SetVisibility(ESlateVisibility::Visible);
	StepCVWP3ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepCVWP4->SetVisibility(ESlateVisibility::Visible);
	StepCVWP4ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepCVBP1->SetVisibility(ESlateVisibility::Visible);
	StepCVBP1ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepCVBP2->SetVisibility(ESlateVisibility::Visible);
	StepCVBP2ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepCVBP3->SetVisibility(ESlateVisibility::Visible);
	StepCVBP3ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepCVBP4->SetVisibility(ESlateVisibility::Visible);
	StepCVBP4ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepCVToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	CV_Main->SetVisibility(ESlateVisibility::Visible);
	CV_WHITEMOVES->SetVisibility(ESlateVisibility::Visible);
	CV_BLACKMOVES->SetVisibility(ESlateVisibility::Visible);
}

///////////////////////////// NAJDORF VARIATION ////////////////////////////////////

void USicilianDefenceUserWidget::StepNVWP1Clicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Visible);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::StepNVWP1ToBackClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Visible);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::StepNVWP2Clicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Visible);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::StepNVWP2ToBackClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Visible);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::StepNVWP3Clicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Visible);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::StepNVWP3ToBackClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Visible);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::StepNVBP1Clicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Visible);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::StepNVBP1ToBackClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Visible);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::StepNVBP2Clicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Visible);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::StepNVBP2ToBackClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Visible);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::StepNVBP3Clicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Visible);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::StepNVBP3ToBackClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Visible);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::StepNVToSelectVariationClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

///////////////////////////// DRAGON VARIATION ////////////////////////////////////

void USicilianDefenceUserWidget::StepDVWP1Clicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Visible);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::StepDVWP1ToBackClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Visible);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::StepDVWP2Clicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Visible);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::StepDVWP2ToBackClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Visible);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::StepDVWP3Clicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Visible);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::StepDVWP3ToBackClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Visible);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::StepDVBP1Clicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Visible);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::StepDVBP1ToBackClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Visible);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::StepDVBP2Clicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Visible);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::StepDVBP2ToBackClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Visible);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::StepDVBP3Clicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Visible);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::StepDVBP3ToBackClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Visible);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::StepDVBP4Clicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Visible);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::StepDVBP4ToBackClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Visible);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

void USicilianDefenceUserWidget::StepDVToSelectVariationClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Hidden);
}

///////////////////////////// CLASSICAL VARIATION ////////////////////////////////////

void USicilianDefenceUserWidget::StepCVWP1Clicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Visible);
}

void USicilianDefenceUserWidget::StepCVWP1ToBackClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Visible);
}

void USicilianDefenceUserWidget::StepCVWP2Clicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Visible);
}

void USicilianDefenceUserWidget::StepCVWP2ToBackClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Visible);
}

void USicilianDefenceUserWidget::StepCVWP3Clicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Visible);
}

void USicilianDefenceUserWidget::StepCVWP3ToBackClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Visible);
}

void USicilianDefenceUserWidget::StepCVWP4Clicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Visible);
}

void USicilianDefenceUserWidget::StepCVWP4ToBackClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Visible);
}

void USicilianDefenceUserWidget::StepCVToSelectVariationClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Visible);
}













































