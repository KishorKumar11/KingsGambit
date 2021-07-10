// King's Gambit by Jonathan Mui and Kishor Kumar


#include "QueensGambitUserWidget.h"
#include "TrainerController.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/CanvasPanel.h"
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
}

void UQueensGambitUserWidget::SelectVariationToThreeClicked()
{
}

void UQueensGambitUserWidget::StepSlavDefenceClicked()
{
}

void UQueensGambitUserWidget::StepQueensGambitDeclinedClicked()
{
}

void UQueensGambitUserWidget::StepQueensGambitAcceptedClicked()
{
}

void UQueensGambitUserWidget::StepSDWP1Clicked()
{
}

void UQueensGambitUserWidget::StepSDWP1ToBackClicked()
{
}

void UQueensGambitUserWidget::StepSDWP2Clicked()
{
}

void UQueensGambitUserWidget::StepSDWP2ToBackClicked()
{
}

void UQueensGambitUserWidget::StepSDWP3Clicked()
{
}

void UQueensGambitUserWidget::StepSDWP3ToBackClicked()
{
}

void UQueensGambitUserWidget::StepSDBP1Clicked()
{
}

void UQueensGambitUserWidget::StepSDBP1ToBackClicked()
{
}

void UQueensGambitUserWidget::StepSDBP2Clicked()
{
}

void UQueensGambitUserWidget::StepSDBP2ToBackClicked()
{
}

void UQueensGambitUserWidget::StepSDBP3Clicked()
{
}

void UQueensGambitUserWidget::StepSDBP3ToBackClicked()
{
}

void UQueensGambitUserWidget::StepSDToSelectVariationClicked()
{
}

void UQueensGambitUserWidget::StepACWP1Clicked()
{
}

void UQueensGambitUserWidget::StepACWP1ToBackClicked()
{
}

void UQueensGambitUserWidget::StepACWP2Clicked()
{
}

void UQueensGambitUserWidget::StepACWP2ToBackClicked()
{
}

void UQueensGambitUserWidget::StepACBP1Clicked()
{
}

void UQueensGambitUserWidget::StepACBP1ToBackClicked()
{
}

void UQueensGambitUserWidget::StepACBP2Clicked()
{
}

void UQueensGambitUserWidget::StepACBP2ToBackClicked()
{
}

void UQueensGambitUserWidget::StepACBP3Clicked()
{
}

void UQueensGambitUserWidget::StepACBP3ToBackClicked()
{
}

void UQueensGambitUserWidget::StepACToSelectVariationClicked()
{
}

void UQueensGambitUserWidget::StepQGAWP1Clicked()
{
}

void UQueensGambitUserWidget::StepQGAWP1ToBackClicked()
{
}

void UQueensGambitUserWidget::StepQGAWP2Clicked()
{
}

void UQueensGambitUserWidget::StepQGAWP2ToBackClicked()
{
}

void UQueensGambitUserWidget::StepQGAWP3Clicked()
{
}

void UQueensGambitUserWidget::StepQGAWP3ToBackClicked()
{
}

void UQueensGambitUserWidget::StepQGABP1Clicked()
{
}

void UQueensGambitUserWidget::StepQGABP1ToBackClicked()
{
}

void UQueensGambitUserWidget::StepQGABP2Clicked()
{
}

void UQueensGambitUserWidget::StepQGABP2ToBackClicked()
{
}

void UQueensGambitUserWidget::StepQGABP3Clicked()
{
}

void UQueensGambitUserWidget::StepQGABP3ToBackClicked()
{
}

void UQueensGambitUserWidget::StepQGAToSelectVariationClicked()
{
}

void UQueensGambitUserWidget::StepSlavDefenseClicked()
{
}

void UQueensGambitUserWidget::StepAlbinCounterGambitClicked()
{
}

