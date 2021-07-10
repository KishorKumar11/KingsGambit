// King's Gambit by Jonathan Mui and Kishor Kumar


#include "ItalianGameUserWidget.h"
#include "TrainerController.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/CanvasPanel.h"
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
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	GiuocoPiano->SetVisibility(ESlateVisibility::Hidden);
	TwoKnightsDefense->SetVisibility(ESlateVisibility::Visible);
	HungarianDefense->SetVisibility(ESlateVisibility::Hidden);
}

void UItalianGameUserWidget::StepSelectVariationToThreeClicked()
{
}

void UItalianGameUserWidget::GiuocoVariationClicked()
{
}

void UItalianGameUserWidget::TwoKnightsDefenseVariationClicked()
{
}

void UItalianGameUserWidget::HungarianDefenseVariationClicked()
{
}

void UItalianGameUserWidget::StepGPWP1Clicked()
{
}

void UItalianGameUserWidget::StepGPWP1ToBackClicked()
{
}

void UItalianGameUserWidget::StepGPWP2Clicked()
{
}

void UItalianGameUserWidget::StepGPWP2ToBackClicked()
{
}

void UItalianGameUserWidget::StepGPWP3Clicked()
{
}

void UItalianGameUserWidget::StepGPWP3ToBackClicked()
{
}

void UItalianGameUserWidget::StepGPBP1Clicked()
{
}

void UItalianGameUserWidget::StepGPBP1ToBackClicked()
{
}

void UItalianGameUserWidget::StepGPBP2Clicked()
{
}

void UItalianGameUserWidget::StepGPBP2ToBackClicked()
{
}

void UItalianGameUserWidget::StepGPBP3Clicked()
{
}

void UItalianGameUserWidget::StepGPBP3ToBackClicked()
{
}

void UItalianGameUserWidget::StepGPBP4Clicked()
{
}

void UItalianGameUserWidget::StepGPBP4ToBackClicked()
{
}

void UItalianGameUserWidget::StepGPToSelectVariationClicked()
{
}

void UItalianGameUserWidget::StepTKDWP1Clicked()
{
}

void UItalianGameUserWidget::StepTKDWP1ToBackClicked()
{
}

void UItalianGameUserWidget::StepTKDWP2Clicked()
{
}

void UItalianGameUserWidget::StepTKDWP2ToBackClicked()
{
}

void UItalianGameUserWidget::StepTKDWP3Clicked()
{
}

void UItalianGameUserWidget::StepTKDWP3ToBackClicked()
{
}

void UItalianGameUserWidget::StepTKDBP1Clicked()
{
}

void UItalianGameUserWidget::StepTKDBP1ToBackClicked()
{
}

void UItalianGameUserWidget::StepTKDBP2Clicked()
{
}

void UItalianGameUserWidget::StepTKDBP2ToBackClicked()
{
}

void UItalianGameUserWidget::StepTKDBP3Clicked()
{
}

void UItalianGameUserWidget::StepTKDBP3ToBackClicked()
{
}

void UItalianGameUserWidget::StepTKDToSelectVariationClicked()
{
}

void UItalianGameUserWidget::StepHDWP1Clicked()
{
}

void UItalianGameUserWidget::StepHDWP1ToBackClicked()
{
}

void UItalianGameUserWidget::StepHDWP2Clicked()
{
}

void UItalianGameUserWidget::StepHDWP2ToBackClicked()
{
}

void UItalianGameUserWidget::StepHDBP1Clicked()
{
}

void UItalianGameUserWidget::StepHDBP1ToBackClicked()
{
}

void UItalianGameUserWidget::StepHDBP2Clicked()
{
}

void UItalianGameUserWidget::StepHDBP2ToBackClicked()
{
}

void UItalianGameUserWidget::StepHDBP3Clicked()
{
}

void UItalianGameUserWidget::StepHDBP3ToBackClicked()
{
}

void UItalianGameUserWidget::StepHDToSelectVariationClicked()
{
}



