// King's Gambit by Jonathan Mui and Kishor Kumar


#include "QueensGambitUserWidget.h"
#include "TrainerController.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/CanvasPanel.h"
#include "Components/Image.h"
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

	StepSDWP1->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepSDWP1Clicked);
	StepSDWP1ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepSDWP1ToBackClicked);
	StepSDWP2->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepSDWP2Clicked);
	StepSDWP2ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepSDWP2ToBackClicked);
	StepSDWP3->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepSDWP3Clicked);
	StepSDWP3ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepSDWP3ToBackClicked);
	StepSDBP1->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepSDBP1Clicked);
	StepSDBP1ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepSDBP1ToBackClicked);
	StepSDBP2->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepSDBP2Clicked);
	StepSDBP2ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepSDBP2ToBackClicked);
	StepSDBP3->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepSDBP3Clicked);
	StepSDBP3ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepSDBP3ToBackClicked);
	StepSDToSelectVariation->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepSDToSelectVariationClicked);

	StepACWP1->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepACWP1Clicked);
	StepACWP1ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepACWP1ToBackClicked);
	StepACWP2->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepACWP2Clicked);
	StepACWP2ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepACWP2ToBackClicked);
	StepACBP1->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepACBP1Clicked);
	StepACBP1ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepACBP1ToBackClicked);
	StepACBP2->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepACBP2Clicked);
	StepACBP2ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepACBP2ToBackClicked);
	StepACBP3->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepACBP3Clicked);
	StepACBP3ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepACBP3ToBackClicked);
	StepACToSelectVariation->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepACToSelectVariationClicked);

	StepQGAWP1->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepQGAWP1Clicked);
	StepQGAWP1ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepQGAWP1ToBackClicked);
	StepQGAWP2->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepQGAWP2Clicked);
	StepQGAWP2ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepQGAWP2ToBackClicked);
	StepQGAWP3->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepQGAWP3Clicked);
	StepQGAWP3ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepQGAWP3ToBackClicked);
	StepQGABP1->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepQGABP1Clicked);
	StepQGABP1ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepQGABP1ToBackClicked);
	StepQGABP2->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepQGABP2Clicked);
	StepQGABP2ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepQGABP2ToBackClicked);
	StepQGABP3->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepQGABP3Clicked);
	StepQGABP3ToBack->OnClicked.AddUniqueDynamic(this, &UQueensGambitUserWidget::StepQGABP3ToBackClicked);
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
	StepSDWP1->SetVisibility(ESlateVisibility::Visible);
	StepSDWP1ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepSDWP2->SetVisibility(ESlateVisibility::Visible);
	StepSDWP2ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepSDWP3->SetVisibility(ESlateVisibility::Visible);
	StepSDWP3ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepSDBP1->SetVisibility(ESlateVisibility::Visible);
	StepSDBP1ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepSDBP2->SetVisibility(ESlateVisibility::Visible);
	StepSDBP2ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepSDBP3->SetVisibility(ESlateVisibility::Visible);
	StepSDBP3ToBack->SetVisibility(ESlateVisibility::Hidden);
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
	StepACWP1->SetVisibility(ESlateVisibility::Visible);
	StepACWP1ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepACWP2->SetVisibility(ESlateVisibility::Visible);
	StepACWP2ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepACBP1->SetVisibility(ESlateVisibility::Visible);
	StepACBP1ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepACBP2->SetVisibility(ESlateVisibility::Visible);
	StepACBP2ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepACBP3->SetVisibility(ESlateVisibility::Visible);
	StepACBP3ToBack->SetVisibility(ESlateVisibility::Hidden);
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
	StepQGAWP1->SetVisibility(ESlateVisibility::Visible);
	StepQGAWP1ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepQGAWP2->SetVisibility(ESlateVisibility::Visible);
	StepQGAWP2ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepQGAWP3->SetVisibility(ESlateVisibility::Visible);
	StepQGAWP3ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepQGABP1->SetVisibility(ESlateVisibility::Visible);
	StepQGABP1ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepQGABP2->SetVisibility(ESlateVisibility::Visible);
	StepQGABP2ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepQGABP3->SetVisibility(ESlateVisibility::Visible);
	StepQGABP3ToBack->SetVisibility(ESlateVisibility::Hidden);
	StepQGAToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	QGA_Main->SetVisibility(ESlateVisibility::Visible);
	QGA_WHITEMOVES->SetVisibility(ESlateVisibility::Visible);
	QGA_BLACKMOVES->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::StepSDWP1Clicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Visible);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepSDWP1ToBackClicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepSDWP2Clicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Visible);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepSDWP2ToBackClicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Visible);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepSDWP3Clicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Visible);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepSDWP3ToBackClicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Visible);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepSDBP1Clicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Visible);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepSDBP1ToBackClicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Visible);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepSDBP2Clicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Visible);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepSDBP2ToBackClicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Visible);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepSDBP3Clicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Visible);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepSDBP3ToBackClicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Visible);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);
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
}

void UQueensGambitUserWidget::StepACWP1Clicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Visible);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepACWP1ToBackClicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Visible);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepACWP2Clicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Visible);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepACWP2ToBackClicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Visible);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepACBP1Clicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Visible);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepACBP1ToBackClicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Visible);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepACBP2Clicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Visible);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepACBP2ToBackClicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Visible);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepACBP3Clicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Visible);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);
}

void UQueensGambitUserWidget::StepACBP3ToBackClicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Visible);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Hidden);
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
}

void UQueensGambitUserWidget::StepQGAWP1Clicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::StepQGAWP1ToBackClicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::StepQGAWP2Clicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::StepQGAWP2ToBackClicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::StepQGAWP3Clicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::StepQGAWP3ToBackClicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::StepQGABP1Clicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::StepQGABP1ToBackClicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::StepQGABP2Clicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::StepQGABP2ToBackClicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::StepQGABP3Clicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Visible);
}

void UQueensGambitUserWidget::StepQGABP3ToBackClicked()
{
	QueensGambitBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	SlavDefense->SetVisibility(ESlateVisibility::Hidden);
	AlbinCounterGambit->SetVisibility(ESlateVisibility::Hidden);
	QueensGambitAccepted->SetVisibility(ESlateVisibility::Visible);
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
}



