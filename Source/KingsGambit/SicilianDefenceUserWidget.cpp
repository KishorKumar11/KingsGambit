// King's Gambit by Jonathan Mui and Kishor Kumar


#include "SicilianDefenceUserWidget.h"
#include "TrainerController.h"
#include "Components/Button.h"
#include "Components/VerticalBox.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/BackgroundBlur.h"
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

	StepSelectVariationToThree->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepSelectVariationToThreeClicked);
	NajdorfVariation->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::NajdorfVariationClicked);
	DragonVariation->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::DragonVariationClicked);
	ClassicalVariation->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::ClassicalVariationClicked);

	StepNVToSelectVariation->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepNVToSelectVariationClicked);
	StepDVToSelectVariation->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepDVToSelectVariationClicked);
	StepCVToSelectVariation->OnClicked.AddUniqueDynamic(this, &USicilianDefenceUserWidget::StepCVToSelectVariationClicked);
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
	SDBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Hidden);

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
	SDBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Hidden);

	Classical->SetVisibility(ESlateVisibility::Hidden);
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
	SDBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Hidden);

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
	SDBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Hidden);

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
	SDBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Hidden);

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
	SDBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Hidden);

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
	SDBG_Variation->SetVisibility(ESlateVisibility::Visible);

	BackgroundBlur_0->SetVisibility(ESlateVisibility::Visible);
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
	StepNVToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	NV_Main->SetVisibility(ESlateVisibility::Visible);
	NV_WHITEMOVES->SetVisibility(ESlateVisibility::Visible);
	NV_BLACKMOVES->SetVisibility(ESlateVisibility::Visible);

	BackgroundBlur->SetVisibility(ESlateVisibility::Visible);
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
	StepDVToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	DV_Main->SetVisibility(ESlateVisibility::Visible);
	DV_WHITEMOVES->SetVisibility(ESlateVisibility::Visible);
	DV_BLACKMOVES->SetVisibility(ESlateVisibility::Visible);

	BackgroundBlur_1->SetVisibility(ESlateVisibility::Visible);
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
	StepCVToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	CV_Main->SetVisibility(ESlateVisibility::Visible);
	CV_WHITEMOVES->SetVisibility(ESlateVisibility::Visible);
	CV_BLACKMOVES->SetVisibility(ESlateVisibility::Visible);

	BackgroundBlur_2->SetVisibility(ESlateVisibility::Visible);
}

///////////////////////////// NAJDORF VARIATION ////////////////////////////////////

void USicilianDefenceUserWidget::StepNVToSelectVariationClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Hidden);

	NajdorfVariation->SetVisibility(ESlateVisibility::Visible);
	DragonVariation->SetVisibility(ESlateVisibility::Visible);
	ClassicalVariation->SetVisibility(ESlateVisibility::Visible);
	StepSelectVariationToThree->SetVisibility(ESlateVisibility::Visible);
	StepVariationToMainMenu->SetVisibility(ESlateVisibility::Visible);
	SDBG_Variation->SetVisibility(ESlateVisibility::Visible);

	BackgroundBlur_0->SetVisibility(ESlateVisibility::Visible);
}

///////////////////////////// DRAGON VARIATION ////////////////////////////////////

void USicilianDefenceUserWidget::StepDVToSelectVariationClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Hidden);

	NajdorfVariation->SetVisibility(ESlateVisibility::Visible);
	DragonVariation->SetVisibility(ESlateVisibility::Visible);
	ClassicalVariation->SetVisibility(ESlateVisibility::Visible);
	StepSelectVariationToThree->SetVisibility(ESlateVisibility::Visible);
	StepVariationToMainMenu->SetVisibility(ESlateVisibility::Visible);
	SDBG_Variation->SetVisibility(ESlateVisibility::Visible);

	BackgroundBlur_0->SetVisibility(ESlateVisibility::Visible);
}

///////////////////////////// CLASSICAL VARIATION ////////////////////////////////////

void USicilianDefenceUserWidget::StepCVToSelectVariationClicked()
{
	SDBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	Najdorf->SetVisibility(ESlateVisibility::Hidden);
	Dragon->SetVisibility(ESlateVisibility::Hidden);
	Classical->SetVisibility(ESlateVisibility::Hidden);

	NajdorfVariation->SetVisibility(ESlateVisibility::Visible);
	DragonVariation->SetVisibility(ESlateVisibility::Visible);
	ClassicalVariation->SetVisibility(ESlateVisibility::Visible);
	StepSelectVariationToThree->SetVisibility(ESlateVisibility::Visible);
	StepVariationToMainMenu->SetVisibility(ESlateVisibility::Visible);
	SDBG_Variation->SetVisibility(ESlateVisibility::Visible);

	BackgroundBlur_0->SetVisibility(ESlateVisibility::Visible);
}













































