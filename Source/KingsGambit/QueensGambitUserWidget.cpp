// King's Gambit by Jonathan Mui and Kishor Kumar


#include "QueensGambitUserWidget.h"
#include "TrainerController.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/CanvasPanel.h"
#include "Components/Image.h"
#include "Components/BackgroundBlur.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UQueensGambitUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	//Gets Trainer Controller
	TrainerController = Cast<ATrainerController>(UGameplayStatics::GetPlayerController(this, 0));

	/********** Inherited Functions for pause **************/
	PauseButton->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::PauseButtonClicked);
	ResumeButton->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::ResumeButtonClicked);
	MainMenuButton->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::MainMenuButtonClicked);
	QuitButton->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::QuitButtonClicked);

	/********** Queen's Gambit Basic **************/
	StepZeroToOne->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepZeroToOneClicked);
	StepOneToZero->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepOneToZeroClicked);
	StepOneToTwo->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepOneToTwoClicked);
	StepTwoToOne->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepTwoToOneClicked);
	StepTwoToThree->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepTwoToThreeClicked);
	StepThreeToTwo->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepThreeToTwoClicked);
	StepThreeToSelectVariation->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepThreeToSelectVariationClicked);

	/********** Select Variation Buttons **************/
	StepSelectVariationToThree->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::SelectVariationToThreeClicked);
	StepVariationToMainMenu->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::MainMenuButtonClicked);
	StepSlavDefense->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepSlavDefenceClicked);
	StepAlbinCounterGambit->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepAlbinCounterGambitClicked);
	StepQueensGambitAccepted->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepQueensGambitAcceptedClicked);

	StepSDToSelectVariation->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepSDToSelectVariationClicked);
	StepACToSelectVariation->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepACToSelectVariationClicked);
	StepQGAToSelectVariation->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepQGAToSelectVariationClicked);

}

/********** Inherited Functions for pause **************/
void UQueensGambitUserWidget::PauseButtonClicked()
{
	Super::PauseButtonClicked();

	ExplanationPanel->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::ResumeButtonClicked()
{
	Super::ResumeButtonClicked();

	ExplanationPanel->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::MainMenuButtonClicked()
{
	Super::MainMenuButtonClicked();
}

void UQueensGambitUserWidget::QuitButtonClicked()
{
	Super::QuitButtonClicked();
}

/********** Queen's Gambit Basic **************/
void UQueensGambitUserWidget::StepZeroToOneClicked()
{

	StepZeroToOne->SetVisibility(ESlateVisibility::Hidden);
	StepZeroTxt->SetVisibility(ESlateVisibility::Hidden);
	StepOneToZero->SetVisibility(ESlateVisibility::Visible);
	StepOneToTwo->SetVisibility(ESlateVisibility::Visible);
	StepOneTxt->SetVisibility(ESlateVisibility::Visible);

	//White's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->WhitePawns[3], FVector(1200.f, 1200.f, 0.5f));
	//Black's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->BlackPawns[3], FVector(1600.f, 1200.f, 0.5f));
}

void UQueensGambitUserWidget::StepOneToZeroClicked()
{

	StepZeroToOne->SetVisibility(ESlateVisibility::Visible);
	StepZeroTxt->SetVisibility(ESlateVisibility::Visible);
	StepOneToZero->SetVisibility(ESlateVisibility::Hidden);
	StepOneToTwo->SetVisibility(ESlateVisibility::Hidden);
	StepOneTxt->SetVisibility(ESlateVisibility::Hidden);

 	//White's Pawn back to its original position
	TrainerController->Move(TrainerController->WhitePawns[3], TrainerController->WhitePawns[3]->OriginalSpawnLocation);
	//Black's Pawn back to its original position
	TrainerController->Move(TrainerController->BlackPawns[3], TrainerController->BlackPawns[3]->OriginalSpawnLocation);
}

void UQueensGambitUserWidget::StepOneToTwoClicked()
{

	StepOneToTwo->SetVisibility(ESlateVisibility::Hidden);
	StepOneToZero->SetVisibility(ESlateVisibility::Hidden);
	StepOneTxt->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToOne->SetVisibility(ESlateVisibility::Visible);
	StepTwoToThree->SetVisibility(ESlateVisibility::Visible);
	StepTwoTxt->SetVisibility(ESlateVisibility::Visible);

	//White's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->WhitePawns[2], FVector(1200.f, 800.f, 0.5f));
}

void UQueensGambitUserWidget::StepTwoToOneClicked()
{

	StepOneToTwo->SetVisibility(ESlateVisibility::Visible);
	StepOneToZero->SetVisibility(ESlateVisibility::Visible);
	StepOneTxt->SetVisibility(ESlateVisibility::Visible);
	StepTwoToOne->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToThree->SetVisibility(ESlateVisibility::Hidden);
	StepTwoTxt->SetVisibility(ESlateVisibility::Hidden);

	//White's Pawn back to its original position
	TrainerController->Move(TrainerController->WhitePawns[2], TrainerController->WhitePawns[2]->OriginalSpawnLocation);
}

void UQueensGambitUserWidget::StepTwoToThreeClicked()
{

	StepTwoToThree->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToOne->SetVisibility(ESlateVisibility::Hidden);
	StepTwoTxt->SetVisibility(ESlateVisibility::Hidden);
	StepThreeToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	StepThreeToTwo->SetVisibility(ESlateVisibility::Visible);
	StepThreeTxt->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::StepThreeToTwoClicked()
{

	StepTwoToThree->SetVisibility(ESlateVisibility::Visible);
	StepTwoToOne->SetVisibility(ESlateVisibility::Visible);
	StepTwoTxt->SetVisibility(ESlateVisibility::Visible);
	StepThreeToTwo->SetVisibility(ESlateVisibility::Hidden);
	StepThreeTxt->SetVisibility(ESlateVisibility::Hidden);
	StepThreeToSelectVariation->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepThreeToSelectVariationClicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);

	StepSlavDefense->SetVisibility(ESlateVisibility::Visible);
	StepAlbinCounterGambit->SetVisibility(ESlateVisibility::Visible);
	StepQueensGambitAccepted->SetVisibility(ESlateVisibility::Visible);
	StepSelectVariationToThree->SetVisibility(ESlateVisibility::Visible);
	StepVariationToMainMenu->SetVisibility(ESlateVisibility::Visible);
	QGBG_Variation->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::SelectVariationToThreeClicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepSlavDefenceClicked()
{
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Visible);


	StepSDTxt->SetVisibility(ESlateVisibility::Visible);
	StepSD1Txt->SetVisibility(ESlateVisibility::Visible);
	StepSDToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	SD_Main->SetVisibility(ESlateVisibility::Visible);
	SD_WHITEMOVES->SetVisibility(ESlateVisibility::Visible);
	SD_BLACKMOVES->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::StepAlbinCounterGambitClicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Visible);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);

	StepACTxt->SetVisibility(ESlateVisibility::Visible);
	StepAC1Txt->SetVisibility(ESlateVisibility::Visible);
	StepACToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	AC_Main->SetVisibility(ESlateVisibility::Visible);
	AC_WHITEMOVES->SetVisibility(ESlateVisibility::Visible);
	AC_BLACKMOVES->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::StepQueensGambitAcceptedClicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Visible);

	StepQGATxt->SetVisibility(ESlateVisibility::Visible);
	StepQGA1Txt->SetVisibility(ESlateVisibility::Visible);
	StepQGAToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	QGA_Main->SetVisibility(ESlateVisibility::Visible);
	QGA_WHITEMOVES->SetVisibility(ESlateVisibility::Visible);
	QGA_BLACKMOVES->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::StepSDToSelectVariationClicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);

	StepSlavDefense->SetVisibility(ESlateVisibility::Visible);
	StepAlbinCounterGambit->SetVisibility(ESlateVisibility::Visible);
	StepQueensGambitAccepted->SetVisibility(ESlateVisibility::Visible);
	StepSelectVariationToThree->SetVisibility(ESlateVisibility::Visible);
	StepVariationToMainMenu->SetVisibility(ESlateVisibility::Visible);
	QGBG_Variation->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::StepACToSelectVariationClicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);

	StepSlavDefense->SetVisibility(ESlateVisibility::Visible);
	StepAlbinCounterGambit->SetVisibility(ESlateVisibility::Visible);
	StepQueensGambitAccepted->SetVisibility(ESlateVisibility::Visible);
	StepSelectVariationToThree->SetVisibility(ESlateVisibility::Visible);
	StepVariationToMainMenu->SetVisibility(ESlateVisibility::Visible);
	QGBG_Variation->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::StepQGAToSelectVariationClicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);

	StepSlavDefense->SetVisibility(ESlateVisibility::Visible);
	StepAlbinCounterGambit->SetVisibility(ESlateVisibility::Visible);
	StepQueensGambitAccepted->SetVisibility(ESlateVisibility::Visible);
	StepSelectVariationToThree->SetVisibility(ESlateVisibility::Visible);
	StepVariationToMainMenu->SetVisibility(ESlateVisibility::Visible);
	QGBG_Variation->SetVisibility(ESlateVisibility::Visible);
}



