// King's Gambit by Jonathan Mui and Kishor Kumar


#include "LondonSystemUserWidget.h"
#include "TrainerController.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/CanvasPanel.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void ULondonSystemUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	//Gets Trainer Controller
	TrainerController = Cast<ATrainerController>(UGameplayStatics::GetPlayerController(this, 0));

	PauseButton->OnClicked.AddUniqueDynamic(this, &ULondonSystemUserWidget::PauseButtonClicked);
	ResumeButton->OnClicked.AddUniqueDynamic(this, &ULondonSystemUserWidget::ResumeButtonClicked);
	MainMenuButton->OnClicked.AddUniqueDynamic(this, &ULondonSystemUserWidget::MainMenuButtonClicked);
	QuitButton->OnClicked.AddUniqueDynamic(this, &ULondonSystemUserWidget::QuitButtonClicked);
	StepZeroToOne->OnClicked.AddUniqueDynamic(this, &ULondonSystemUserWidget::StepZeroToOneClicked);
	StepOneToZero->OnClicked.AddUniqueDynamic(this, &ULondonSystemUserWidget::StepOneToZeroClicked);
	StepOneToTwo->OnClicked.AddUniqueDynamic(this, &ULondonSystemUserWidget::StepOneToTwoClicked);
	StepTwoToOne->OnClicked.AddUniqueDynamic(this, &ULondonSystemUserWidget::StepTwoToOneClicked);
	StepTwoToThree->OnClicked.AddUniqueDynamic(this, &ULondonSystemUserWidget::StepTwoToThreeClicked);
	StepThreeToTwo->OnClicked.AddUniqueDynamic(this, &ULondonSystemUserWidget::StepThreeToTwoClicked);
	StepThreeToMainMenu->OnClicked.AddUniqueDynamic(this, &ULondonSystemUserWidget::MainMenuButtonClicked);
}

void ULondonSystemUserWidget::PauseButtonClicked()
{
	Super::PauseButtonClicked();

	ExplanationPanel->SetVisibility(ESlateVisibility::Hidden);
}

void ULondonSystemUserWidget::ResumeButtonClicked()
{
	Super::ResumeButtonClicked();

	ExplanationPanel->SetVisibility(ESlateVisibility::Visible);
}

void ULondonSystemUserWidget::MainMenuButtonClicked()
{
	Super::MainMenuButtonClicked();
}

void ULondonSystemUserWidget::QuitButtonClicked()
{
	Super::QuitButtonClicked();
}

void ULondonSystemUserWidget::StepZeroToOneClicked()
{
	StepZeroToOne->SetVisibility(ESlateVisibility::Hidden);
	StepZeroTxt->SetVisibility(ESlateVisibility::Hidden);
	StepOneToZero->SetVisibility(ESlateVisibility::Visible);
	StepOneToTwo->SetVisibility(ESlateVisibility::Visible);
	StepOneTxt->SetVisibility(ESlateVisibility::Visible);

	//White's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->WhitePawns[3], FVector(1200.f, 1200.f, 0.5f));
}

void ULondonSystemUserWidget::StepOneToZeroClicked()
{
	StepZeroToOne->SetVisibility(ESlateVisibility::Visible);
	StepZeroTxt->SetVisibility(ESlateVisibility::Visible);
	StepOneToZero->SetVisibility(ESlateVisibility::Hidden);
	StepOneTxt->SetVisibility(ESlateVisibility::Hidden);

	//White's Pawn back to its original position
	TrainerController->Move(TrainerController->WhitePawns[3], TrainerController->WhitePawns[3]->OriginalSpawnLocation);

}

void ULondonSystemUserWidget::StepOneToTwoClicked()
{
	StepOneToTwo->SetVisibility(ESlateVisibility::Hidden);
	StepOneToZero->SetVisibility(ESlateVisibility::Hidden);
	StepOneTxt->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToOne->SetVisibility(ESlateVisibility::Visible);
	StepTwoToThree->SetVisibility(ESlateVisibility::Visible);
	StepTwoTxt->SetVisibility(ESlateVisibility::Visible);

	//Black's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->BlackPawns[3], FVector(1600.f, 1200.f, 0.5f));
	//Black's Pawn Moves 2 steps forward
	TrainerController->Move(TrainerController->BlackKnights[1], FVector(2000.f, 2000.f, 0.5f));


}

void ULondonSystemUserWidget::StepTwoToOneClicked()
{
	StepOneToTwo->SetVisibility(ESlateVisibility::Visible);
	StepOneToZero->SetVisibility(ESlateVisibility::Visible);
	StepOneTxt->SetVisibility(ESlateVisibility::Visible);
	StepTwoToOne->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToThree->SetVisibility(ESlateVisibility::Hidden);
	StepTwoTxt->SetVisibility(ESlateVisibility::Hidden);

	//Black's Pawn back to its original position
	TrainerController->Move(TrainerController->BlackPawns[3], TrainerController->BlackPawns[3]->OriginalSpawnLocation);
	//Black's Pawn back to its original position
	TrainerController->Move(TrainerController->BlackKnights[1], TrainerController->BlackKnights[1]->OriginalSpawnLocation);
}

void ULondonSystemUserWidget::StepTwoToThreeClicked()
{
	StepTwoToThree->SetVisibility(ESlateVisibility::Hidden);
	StepTwoToOne->SetVisibility(ESlateVisibility::Hidden);
	StepTwoTxt->SetVisibility(ESlateVisibility::Hidden);
	StepThreeToMainMenu->SetVisibility(ESlateVisibility::Visible);
	StepThreeToTwo->SetVisibility(ESlateVisibility::Visible);
	StepThreeTxt->SetVisibility(ESlateVisibility::Visible);

	//White's King's Bishop moves forward to pin the opponents Knight 
	TrainerController->Move(TrainerController->WhiteBishops[0], FVector(1200.f, 2000.f, 0.5f));
}

void ULondonSystemUserWidget::StepThreeToTwoClicked()
{
	StepTwoToThree->SetVisibility(ESlateVisibility::Visible);
	StepTwoToOne->SetVisibility(ESlateVisibility::Visible);
	StepTwoTxt->SetVisibility(ESlateVisibility::Visible);
	StepThreeToTwo->SetVisibility(ESlateVisibility::Hidden);
	StepThreeTxt->SetVisibility(ESlateVisibility::Hidden);
	StepThreeToMainMenu->SetVisibility(ESlateVisibility::Hidden);

	//White's Bishop back to its original position
	TrainerController->Move(TrainerController->WhiteBishops[0], TrainerController->WhiteBishops[0]->OriginalSpawnLocation);
}

void ULondonSystemUserWidget::StepThreeToSelect_VariationClicked()
{
}

void ULondonSystemUserWidget::StepSelectVariationToThreeClicked()
{
}

void ULondonSystemUserWidget::Stepg6ToSelectVariationClicked()
{
}

void ULondonSystemUserWidget::Stepe6c5WP1Clicked()
{
}

void ULondonSystemUserWidget::Stepe6c5WP1ToBackClicked()
{
}

void ULondonSystemUserWidget::Stepe6c5WP2Clicked()
{
}

void ULondonSystemUserWidget::Stepe6c5WP2ToBackClicked()
{
}

void ULondonSystemUserWidget::Stepe6c5BP1Clicked()
{
}

void ULondonSystemUserWidget::Stepe6c5BP1ToBackClicked()
{
}

void ULondonSystemUserWidget::Stepe6c5BP2Clicked()
{
}

void ULondonSystemUserWidget::Stepe6c5BP2ToBackClicked()
{
}

void ULondonSystemUserWidget::Stepe6c5ToSelectVariationClicked()
{
}

void ULondonSystemUserWidget::Stepe6WP1Clicked()
{
}

void ULondonSystemUserWidget::Stepe6WP1ToBackClicked()
{
}

void ULondonSystemUserWidget::Stepe6WP2Clicked()
{
}

void ULondonSystemUserWidget::Stepe6WP2ToBackClicked()
{
}

void ULondonSystemUserWidget::Stepe6BP1Clicked()
{
}

void ULondonSystemUserWidget::Stepe6BP1ToBackClicked()
{
}

void ULondonSystemUserWidget::Stepe6BP2Clicked()
{
}

void ULondonSystemUserWidget::Stepe6BP2ToBackClicked()
{
}

void ULondonSystemUserWidget::Stepe6ToSelectVariationClicked()
{
}

void ULondonSystemUserWidget::Stepg6Clicked()
{
}

void ULondonSystemUserWidget::Stepe6c5Clicked()
{
}

void ULondonSystemUserWidget::Stepe6Clicked()
{
}

void ULondonSystemUserWidget::Stepg6WP1Clicked()
{
}

void ULondonSystemUserWidget::Stepg6WP1ToBackClicked()
{
}

void ULondonSystemUserWidget::Stepg6WP2Clicked()
{
}

void ULondonSystemUserWidget::Stepg6WP2ToBackClicked()
{
}

void ULondonSystemUserWidget::Stepg6BP1Clicked()
{
}

void ULondonSystemUserWidget::Stepg6BP1ToBackClicked()
{
}

void ULondonSystemUserWidget::Stepg6BP2Clicked()
{
}

void ULondonSystemUserWidget::Stepg6BP2ToBackClicked()
{
}

