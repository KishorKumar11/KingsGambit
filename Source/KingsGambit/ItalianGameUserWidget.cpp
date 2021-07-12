// King's Gambit by Jonathan Mui and Kishor Kumar


#include "ItalianGameUserWidget.h"
#include "TrainerController.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/CanvasPanel.h"
#include "Components/Image.h"
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
	StepThreeToMainMenu->OnClicked.AddUniqueDynamic(this, &UItalianGameUserWidget::MainMenuButtonClicked);

	//StepGPWP1->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepGPWP1Clicked);
	//StepGPWP1ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepGPWP1ToBackClicked);
	//StepGPWP2->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepGPWP2Clicked);
	//StepGPWP2ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepGPWP2ToBackClicked);
	//StepGPWP3->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepGPWP3Clicked);
	//StepGPWP3ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepGPWP3ToBackClicked);
	//StepGPBP1->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepGPBP1Clicked);
	//StepGPBP1ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepGPBP1ToBackClicked);
	//StepGPBP2->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepGPBP2Clicked);
	//StepGPBP2ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepGPBP2ToBackClicked);
	//StepGPBP3->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepGPBP3Clicked);
	//StepGPBP3ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepGPBP3ToBackClicked);
	//StepGPBP4->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepGPBP3Clicked);
	//StepGPBP4ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepGPBP3ToBackClicked);
	//StepGPToSelectVariation->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepGPToSelectVariationClicked);

	//StepTKDWP1->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepTKDWP1Clicked);
	//StepTKDWP1ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepTKDWP1ToBackClicked);
	//StepTKDWP2->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepTKDWP2Clicked);
	//StepTKDWP2ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepTKDWP2ToBackClicked);
	//StepTKDWP3->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepTKDWP2Clicked);
	//StepTKDWP3ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepTKDWP2ToBackClicked);
	//StepTKDBP1->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepTKDBP1Clicked);
	//StepTKDBP1ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepTKDBP1ToBackClicked);
	//StepTKDBP2->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepTKDBP2Clicked);
	//StepTKDBP2ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepTKDBP2ToBackClicked);
	//StepTKDBP3->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepDVBP3Clicked);
	//StepTKDBP3ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepTKDBP3ToBackClicked);
	//StepTKDToSelectVariation->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::TKDToSelectVariationClicked);

	//StepHDWP1->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepHDWP1Clicked);
	//StepHDWP1ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepHDWP1ToBackClicked);
	//StepHDWP2->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepHDWP2Clicked);
	//StepHDWP2ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepHDWP2ToBackClicked);
	//StepHDBP1->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepHDBP1Clicked);
	//StepHDBP1ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepHDBP1ToBackClicked);
	//StepHDBP2->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepHDBP2Clicked);
	//StepHDBP2ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepHDBP2ToBackClicked);
	//StepHDBP3->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepHDBP3Clicked);
	//StepHDBP3ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepHDBP3ToBackClicked);
	//StepHDToSelectVariation->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::HDToSelectVariationClicked);
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
	StepTwoToThree->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToOne->SetVisibility(ESlateVisibility::Hidden);
	StepTwoTxt->SetVisibility(ESlateVisibility::Hidden);
	StepThreeToMainMenu->SetVisibility(ESlateVisibility::Visible);
	StepThreeToTwo->SetVisibility(ESlateVisibility::Visible);
	StepThreeTxt->SetVisibility(ESlateVisibility::Visible);

	//White's King Side Bishop Moves forward
	TrainerController->Move(TrainerController->WhiteBishops[1], FVector(1200.f, 800.f, 0.5f));
}

void UItalianGameUserWidget::StepThreeToTwoClicked()
{
	StepTwoToThree->SetVisibility(ESlateVisibility::Visible);
	StepTwoToOne->SetVisibility(ESlateVisibility::Visible);
	StepTwoTxt->SetVisibility(ESlateVisibility::Visible);
	StepThreeToTwo->SetVisibility(ESlateVisibility::Hidden);
	StepThreeTxt->SetVisibility(ESlateVisibility::Hidden);
	StepThreeToMainMenu->SetVisibility(ESlateVisibility::Hidden);

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
	StepGPWP1->SetVisibility(ESlateVisibility::Visible);
	StepGPWP1ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepGPWP2->SetVisibility(ESlateVisibility::Visible);
	StepGPWP2ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepGPWP3->SetVisibility(ESlateVisibility::Visible);
	StepGPWP3ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepGPBP1->SetVisibility(ESlateVisibility::Visible);
	StepGPBP1ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepGPBP2->SetVisibility(ESlateVisibility::Visible);
	StepGPBP2ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepGPBP3->SetVisibility(ESlateVisibility::Visible);
	StepGPBP3ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepGPBP4->SetVisibility(ESlateVisibility::Visible);
	StepGPBP4ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepGPToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	GP_Main->SetVisibility(ESlateVisibility::Visible);
	GP_WHITEMOVES->SetVisibility(ESlateVisibility::Visible);
	GP_BLACKMOVES->SetVisibility(ESlateVisibility::Visible);
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
	StepTKDWP1->SetVisibility(ESlateVisibility::Visible);
	StepTKDWP1ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepTKDWP2->SetVisibility(ESlateVisibility::Visible);
	StepTKDWP2ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepTKDWP3->SetVisibility(ESlateVisibility::Visible);
	StepTKDWP3ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepTKDBP1->SetVisibility(ESlateVisibility::Visible);
	StepTKDBP1ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepTKDBP2->SetVisibility(ESlateVisibility::Visible);
	StepTKDBP2ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepTKDBP3->SetVisibility(ESlateVisibility::Visible);
	StepTKDBP3ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepTKDToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	TKD_Main->SetVisibility(ESlateVisibility::Visible);
	TKD_WHITEMOVES->SetVisibility(ESlateVisibility::Visible);
	TKD_BLACKMOVES->SetVisibility(ESlateVisibility::Visible);
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
	StepHDWP1->SetVisibility(ESlateVisibility::Visible);
	StepHDWP1ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepHDWP2->SetVisibility(ESlateVisibility::Visible);
	StepHDWP2ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepHDBP1->SetVisibility(ESlateVisibility::Visible);
	StepHDBP1ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepHDBP2->SetVisibility(ESlateVisibility::Visible);
	StepHDBP2ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepHDBP3->SetVisibility(ESlateVisibility::Visible);
	StepHDBP3ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepHDToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	HD_Main->SetVisibility(ESlateVisibility::Visible);
	HD_WHITEMOVES->SetVisibility(ESlateVisibility::Visible);
	HD_BLACKMOVES->SetVisibility(ESlateVisibility::Visible);
}

void UItalianGameUserWidget::StepGPWP1Clicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Visible);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepGPWP1ToBackClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Visible);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepGPWP2Clicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Visible);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepGPWP2ToBackClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Visible);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepGPWP3Clicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Visible);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepGPWP3ToBackClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Visible);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepGPBP1Clicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Visible);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepGPBP1ToBackClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Visible);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepGPBP2Clicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Visible);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepGPBP2ToBackClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Visible);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepGPBP3Clicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Visible);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepGPBP3ToBackClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Visible);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepGPBP4Clicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Visible);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepGPBP4ToBackClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Visible);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepGPToSelectVariationClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepTKDWP1Clicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Visible);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepTKDWP1ToBackClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Visible);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepTKDWP2Clicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Visible);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepTKDWP2ToBackClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Visible);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepTKDWP3Clicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Visible);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepTKDWP3ToBackClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Visible);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepTKDBP1Clicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Visible);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepTKDBP1ToBackClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Visible);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepTKDBP2Clicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Visible);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepTKDBP2ToBackClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Visible);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepTKDBP3Clicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Visible);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepTKDBP3ToBackClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Visible);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepTKDToSelectVariationClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepHDWP1Clicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Visible);
}

void UItalianGameUserWidget::StepHDWP1ToBackClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Visible);
}

void UItalianGameUserWidget::StepHDWP2Clicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Visible);
}

void UItalianGameUserWidget::StepHDWP2ToBackClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Visible);
}

void UItalianGameUserWidget::StepHDBP1Clicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Visible);
}

void UItalianGameUserWidget::StepHDBP1ToBackClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Visible);
}

void UItalianGameUserWidget::StepHDBP2Clicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Visible);
}

void UItalianGameUserWidget::StepHDBP2ToBackClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Visible);
}

void UItalianGameUserWidget::StepHDBP3Clicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Visible);
}

void UItalianGameUserWidget::StepHDBP3ToBackClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Visible);
}

void UItalianGameUserWidget::StepHDToSelectVariationClicked()
{
	ItalianGameBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Hidden);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}



