// King's Gambit by Jonathan Mui and Kishor Kumar


#include "ItalianGameUserWidget.h"
#include "TrainerController.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/CanvasPanel.h"
#include "Components/Image.h"
#include "Components/BackgroundBlur.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UItalianGameUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	//Gets Trainer Controller
	TrainerController = Cast<ATrainerController>(UGameplayStatics::GetPlayerController(this, 0));

	PauseButton->OnClicked.AddUniqueDynamic(this, &UItalianGameUserWidget::PauseButtonClicked);
	ResumeButton->OnClicked.AddUniqueDynamic(this, &UItalianGameUserWidget::ResumeButtonClicked);
	MainMenuButton->OnClicked.AddUniqueDynamic(this, &UItalianGameUserWidget::MainMenuButtonClicked);
	QuitButton->OnClicked.AddUniqueDynamic(this, &UItalianGameUserWidget::QuitButtonClicked);
	StepZeroToOne->OnClicked.AddUniqueDynamic(this, &UItalianGameUserWidget::StepZeroToOneClicked);
	StepOneToZero->OnClicked.AddUniqueDynamic(this, &UItalianGameUserWidget::StepOneToZeroClicked);
	StepOneToTwo->OnClicked.AddUniqueDynamic(this, &UItalianGameUserWidget::StepOneToTwoClicked);
	StepTwoToOne->OnClicked.AddUniqueDynamic(this, &UItalianGameUserWidget::StepTwoToOneClicked);
	StepTwoToThree->OnClicked.AddUniqueDynamic(this, &UItalianGameUserWidget::StepTwoToThreeClicked);
	StepThreeToTwo->OnClicked.AddUniqueDynamic(this, &UItalianGameUserWidget::StepThreeToTwoClicked);
	StepVariationToMainMenu->OnClicked.AddUniqueDynamic(this, &UItalianGameUserWidget::MainMenuButtonClicked);
	StepThreeToSelect_Variation->OnClicked.AddUniqueDynamic(this, &UItalianGameUserWidget::StepThreeToSelect_VariationClicked);

	StepSelectVariationToThree->OnClicked.AddUniqueDynamic(this, &UItalianGameUserWidget::StepSelectVariationToThreeClicked);
	GiuocoPianoVariation->OnClicked.AddUniqueDynamic(this, &UItalianGameUserWidget::GiuocoVariationClicked);
	TwoKnightsDefenseVariation->OnClicked.AddUniqueDynamic(this, &UItalianGameUserWidget::TwoKnightsDefenseVariationClicked);
	HungarianDefenseVariation->OnClicked.AddUniqueDynamic(this, &UItalianGameUserWidget::HungarianDefenseVariationClicked);

	StepGPToSelectVariation->OnClicked.AddUniqueDynamic(this, &UItalianGameUserWidget::StepGPToSelectVariationClicked);
	StepTKDToSelectVariation->OnClicked.AddUniqueDynamic(this, &UItalianGameUserWidget::StepTKDToSelectVariationClicked);
	StepHDToSelectVariation->OnClicked.AddUniqueDynamic(this, &UItalianGameUserWidget::StepHDToSelectVariationClicked);
}

void UItalianGameUserWidget::PauseButtonClicked()
{
	Super::PauseButtonClicked();

	ExplanationPanel->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::ResumeButtonClicked()
{
	Super::ResumeButtonClicked();

	ExplanationPanel->SetVisibility(ESlateVisibility::Visible);
}

void UItalianGameUserWidget::MainMenuButtonClicked()
{
	Super::MainMenuButtonClicked();
}

void UItalianGameUserWidget::QuitButtonClicked()
{
	Super::QuitButtonClicked();
}

void UItalianGameUserWidget::StepZeroToOneClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);

	StepZeroToOne->SetVisibility(ESlateVisibility::Hidden);
	StepZeroTxt->SetVisibility(ESlateVisibility::Hidden);
	StepOneToZero->SetVisibility(ESlateVisibility::Visible);
	StepOneToTwo->SetVisibility(ESlateVisibility::Visible);
	StepOneTxt->SetVisibility(ESlateVisibility::Visible);

	//White's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->WhitePawns[4], FVector(1200.f, 1600.f, 0.5f));
	//Black's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->BlackPawns[4], FVector(1600.f, 1600.f, 0.5f));
}

void UItalianGameUserWidget::StepOneToZeroClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);

	StepZeroToOne->SetVisibility(ESlateVisibility::Visible);
	StepZeroTxt->SetVisibility(ESlateVisibility::Visible);
	StepOneToZero->SetVisibility(ESlateVisibility::Hidden);
	StepOneTxt->SetVisibility(ESlateVisibility::Hidden);

	//White's Pawn back to its original position
	TrainerController->Move(TrainerController->WhitePawns[4], TrainerController->WhitePawns[4]->OriginalSpawnLocation);
	//Black's Pawn back to its original position
	TrainerController->Move(TrainerController->BlackPawns[4], TrainerController->BlackPawns[4]->OriginalSpawnLocation);
}

void UItalianGameUserWidget::StepOneToTwoClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);

	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
	StepOneToTwo->SetVisibility(ESlateVisibility::Hidden);
	StepOneToZero->SetVisibility(ESlateVisibility::Hidden);
	StepOneTxt->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToOne->SetVisibility(ESlateVisibility::Visible);
	StepTwoToThree->SetVisibility(ESlateVisibility::Visible);
	StepTwoTxt->SetVisibility(ESlateVisibility::Visible);

	//White's King Side Knight Moves forward
	TrainerController->Move(TrainerController->WhiteKnights[1], FVector(800.f, 2000.f, 0.5f));
	//Black's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->BlackKnights[0], FVector(2000.f, 800.f, 0.5f));
}

void UItalianGameUserWidget::StepTwoToOneClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);

	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
	StepOneToTwo->SetVisibility(ESlateVisibility::Visible);
	StepOneToZero->SetVisibility(ESlateVisibility::Visible);
	StepOneTxt->SetVisibility(ESlateVisibility::Visible);
	StepTwoToOne->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToThree->SetVisibility(ESlateVisibility::Hidden);
	StepTwoTxt->SetVisibility(ESlateVisibility::Hidden);

	//White's Knight back to its original position
	TrainerController->Move(TrainerController->WhiteKnights[1], TrainerController->WhitePawns[1]->OriginalSpawnLocation);
	//Black's  back to its original position
	TrainerController->Move(TrainerController->BlackKnights[0], TrainerController->BlackPawns[0]->OriginalSpawnLocation);
}

void UItalianGameUserWidget::StepTwoToThreeClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);

	StepTwoToThree->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToOne->SetVisibility(ESlateVisibility::Hidden);
	StepTwoTxt->SetVisibility(ESlateVisibility::Hidden);
	StepThreeToSelect_Variation->SetVisibility(ESlateVisibility::Visible);
	StepThreeToTwo->SetVisibility(ESlateVisibility::Visible);
	StepThreeTxt->SetVisibility(ESlateVisibility::Visible);

	//White's King Side Bishop Moves forward
	TrainerController->Move(TrainerController->WhiteBishops[1], FVector(1200.f, 800.f, 0.5f));
}

void UItalianGameUserWidget::StepThreeToTwoClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);

	StepTwoToThree->SetVisibility(ESlateVisibility::Visible);
	StepTwoToOne->SetVisibility(ESlateVisibility::Visible);
	StepTwoTxt->SetVisibility(ESlateVisibility::Visible);
	StepThreeToTwo->SetVisibility(ESlateVisibility::Hidden);
	StepThreeTxt->SetVisibility(ESlateVisibility::Hidden);
	StepThreeToSelect_Variation->SetVisibility(ESlateVisibility::Hidden);

	//White's Bishop back to its original position
	TrainerController->Move(TrainerController->WhiteBishops[1], TrainerController->WhiteBishops[1]->OriginalSpawnLocation);
}

void UItalianGameUserWidget::StepThreeToSelect_VariationClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible); 
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);

	StepThreeToTwo->SetVisibility(ESlateVisibility::Hidden);
	StepThreeTxt->SetVisibility(ESlateVisibility::Hidden);
	StepThreeToSelect_Variation->SetVisibility(ESlateVisibility::Hidden);

	GiuocoPianoVariation->SetVisibility(ESlateVisibility::Visible);
	TwoKnightsDefenseVariation->SetVisibility(ESlateVisibility::Visible);
	HungarianDefenseVariation->SetVisibility(ESlateVisibility::Visible);
	StepSelectVariationToThree->SetVisibility(ESlateVisibility::Visible);
	StepVariationToMainMenu->SetVisibility(ESlateVisibility::Visible);
	IGBG_Variation->SetVisibility(ESlateVisibility::Visible);

	BackgroundBlur_0->SetVisibility(ESlateVisibility::Visible);
}

void UItalianGameUserWidget::StepSelectVariationToThreeClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::GiuocoVariationClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Visible);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);

	StepGPTxt->SetVisibility(ESlateVisibility::Visible);
	StepGP1Txt->SetVisibility(ESlateVisibility::Visible);
	StepGPToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	GP_Main->SetVisibility(ESlateVisibility::Visible);
	GP_WHITEMOVES->SetVisibility(ESlateVisibility::Visible);
	GP_BLACKMOVES->SetVisibility(ESlateVisibility::Visible);

	BackgroundBlur->SetVisibility(ESlateVisibility::Visible);
}

void UItalianGameUserWidget::TwoKnightsDefenseVariationClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Visible);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);

	StepTKDTxt->SetVisibility(ESlateVisibility::Visible);
	StepTKD1Txt->SetVisibility(ESlateVisibility::Visible);
	StepTKDToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	TKD_Main->SetVisibility(ESlateVisibility::Visible);
	TKD_WHITEMOVES->SetVisibility(ESlateVisibility::Visible);
	TKD_BLACKMOVES->SetVisibility(ESlateVisibility::Visible);

	BackgroundBlur_1->SetVisibility(ESlateVisibility::Visible);
}

void UItalianGameUserWidget::HungarianDefenseVariationClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Visible);

	StepHDTxt->SetVisibility(ESlateVisibility::Visible);
	StepHD1Txt->SetVisibility(ESlateVisibility::Visible);
	StepHDToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	HD_Main->SetVisibility(ESlateVisibility::Visible);
	HD_WHITEMOVES->SetVisibility(ESlateVisibility::Visible);
	HD_BLACKMOVES->SetVisibility(ESlateVisibility::Visible);

	BackgroundBlur_2->SetVisibility(ESlateVisibility::Visible);
}

void UItalianGameUserWidget::StepGPToSelectVariationClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);

	BackgroundBlur_0->SetVisibility(ESlateVisibility::Visible);
}

void UItalianGameUserWidget::StepTKDToSelectVariationClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);

	BackgroundBlur_0->SetVisibility(ESlateVisibility::Visible);
}

void UItalianGameUserWidget::StepHDToSelectVariationClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);

	BackgroundBlur_0->SetVisibility(ESlateVisibility::Visible);
}



