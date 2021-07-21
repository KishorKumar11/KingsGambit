// King's Gambit by Jonathan Mui and Kishor Kumar


#include "LondonSystemUserWidget.h"
#include "TrainerController.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/CanvasPanel.h"
#include "Components/Image.h"
#include "Components/BackgroundBlur.h"
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
	StepVariationToMainMenu->OnClicked.AddUniqueDynamic(this, &ULondonSystemUserWidget::MainMenuButtonClicked);
	StepThreeToSelect_Variation->OnClicked.AddUniqueDynamic(this, &ULondonSystemUserWidget::StepThreeToSelect_VariationClicked);

	StepSelectVariationToThree->OnClicked.AddUniqueDynamic(this, &ULondonSystemUserWidget::StepSelectVariationToThreeClicked);
	Stepg6Variation->OnClicked.AddUniqueDynamic(this, &ULondonSystemUserWidget::Stepg6Clicked);
	Stepe6c5Variation->OnClicked.AddUniqueDynamic(this, &ULondonSystemUserWidget::Stepe6c5Clicked);
	Stepe6Variation->OnClicked.AddUniqueDynamic(this, &ULondonSystemUserWidget::Stepe6Clicked);

	Stepg6ToSelectVariation->OnClicked.AddUniqueDynamic(this, &ULondonSystemUserWidget::Stepg6ToSelectVariationClicked);
	Stepe6ToSelectVariation->OnClicked.AddUniqueDynamic(this, &ULondonSystemUserWidget::Stepe6ToSelectVariationClicked);
	Stepe6c5ToSelectVariation->OnClicked.AddUniqueDynamic(this, &ULondonSystemUserWidget::Stepe6c5ToSelectVariationClicked);
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
	StepOneToTwo->SetVisibility(ESlateVisibility::Hidden);
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
	StepThreeToSelect_Variation->SetVisibility(ESlateVisibility::Visible);
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
	StepThreeToSelect_Variation->SetVisibility(ESlateVisibility::Hidden);

	//White's Bishop back to its original position
	TrainerController->Move(TrainerController->WhiteBishops[0], TrainerController->WhiteBishops[0]->OriginalSpawnLocation);
}

void ULondonSystemUserWidget::StepThreeToSelect_VariationClicked()
{
	LondonSystemBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);

	Stepg6Variation->SetVisibility(ESlateVisibility::Visible);
	Stepe6Variation->SetVisibility(ESlateVisibility::Visible);
	Stepe6c5Variation->SetVisibility(ESlateVisibility::Visible);
	StepSelectVariationToThree->SetVisibility(ESlateVisibility::Visible);
	StepVariationToMainMenu->SetVisibility(ESlateVisibility::Visible);
	LSBG_Variation->SetVisibility(ESlateVisibility::Visible);
	SelectVariationTxt->SetVisibility(ESlateVisibility::Visible);

	BackgroundBlur_0->SetVisibility(ESlateVisibility::Visible);
}

void ULondonSystemUserWidget::StepSelectVariationToThreeClicked()
{
	LondonSystemBasic->SetVisibility(ESlateVisibility::Visible);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
}

void ULondonSystemUserWidget::Stepg6ToSelectVariationClicked()
{
	LondonSystemBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	Withg6->SetVisibility(ESlateVisibility::Hidden);
	Withe6c5->SetVisibility(ESlateVisibility::Hidden);
	Withe6->SetVisibility(ESlateVisibility::Hidden);

	Stepg6Variation->SetVisibility(ESlateVisibility::Visible);
	Stepe6Variation->SetVisibility(ESlateVisibility::Visible);
	Stepe6c5Variation->SetVisibility(ESlateVisibility::Visible);
	StepSelectVariationToThree->SetVisibility(ESlateVisibility::Visible);
	StepVariationToMainMenu->SetVisibility(ESlateVisibility::Visible); 
	LSBG_Variation->SetVisibility(ESlateVisibility::Visible);
	SelectVariationTxt->SetVisibility(ESlateVisibility::Visible);

	BackgroundBlur_0->SetVisibility(ESlateVisibility::Visible);
}

void ULondonSystemUserWidget::Stepe6ToSelectVariationClicked()
{
	LondonSystemBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	Withg6->SetVisibility(ESlateVisibility::Hidden);
	Withe6c5->SetVisibility(ESlateVisibility::Hidden);
	Withe6->SetVisibility(ESlateVisibility::Hidden);

	Stepg6Variation->SetVisibility(ESlateVisibility::Visible);
	Stepe6Variation->SetVisibility(ESlateVisibility::Visible);
	Stepe6c5Variation->SetVisibility(ESlateVisibility::Visible);
	StepSelectVariationToThree->SetVisibility(ESlateVisibility::Visible);
	StepVariationToMainMenu->SetVisibility(ESlateVisibility::Visible);
	LSBG_Variation->SetVisibility(ESlateVisibility::Visible);
	SelectVariationTxt->SetVisibility(ESlateVisibility::Visible);

	BackgroundBlur_0->SetVisibility(ESlateVisibility::Visible);
}

void ULondonSystemUserWidget::Stepg6Clicked()
{
	LondonSystemBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Withg6->SetVisibility(ESlateVisibility::Visible);
	Withe6c5->SetVisibility(ESlateVisibility::Hidden);
	Withe6->SetVisibility(ESlateVisibility::Hidden);

	Stepg6Txt->SetVisibility(ESlateVisibility::Visible);
	Stepg61Txt->SetVisibility(ESlateVisibility::Visible);
	Stepg6ToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	g6_Main->SetVisibility(ESlateVisibility::Visible);
	g6_WHITEMOVES->SetVisibility(ESlateVisibility::Visible);
	g6_BLACKMOVES->SetVisibility(ESlateVisibility::Visible);

	BackgroundBlur->SetVisibility(ESlateVisibility::Visible);
}

void ULondonSystemUserWidget::Stepe6c5Clicked()
{
	LondonSystemBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Withg6->SetVisibility(ESlateVisibility::Hidden);
	Withe6c5->SetVisibility(ESlateVisibility::Visible);
	Withe6->SetVisibility(ESlateVisibility::Hidden);

	Stepe6c5Txt->SetVisibility(ESlateVisibility::Visible);
	Stepe6c51Txt->SetVisibility(ESlateVisibility::Visible);
	Stepe6c5ToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	e6c5_Main->SetVisibility(ESlateVisibility::Visible);
	e6c5_WHITEMOVES->SetVisibility(ESlateVisibility::Visible);
	e6c5_BLACKMOVES->SetVisibility(ESlateVisibility::Visible);

	BackgroundBlur_1->SetVisibility(ESlateVisibility::Visible);
}

void ULondonSystemUserWidget::Stepe6Clicked()
{
	LondonSystemBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Hidden);
	Withg6->SetVisibility(ESlateVisibility::Hidden);
	Withe6c5->SetVisibility(ESlateVisibility::Hidden);
	Withe6->SetVisibility(ESlateVisibility::Visible);

	Stepe6Txt->SetVisibility(ESlateVisibility::Visible);
	Stepe61Txt->SetVisibility(ESlateVisibility::Visible);
	Stepe6ToSelectVariation->SetVisibility(ESlateVisibility::Visible);
	e6_Main->SetVisibility(ESlateVisibility::Visible);
	e6_WHITEMOVES->SetVisibility(ESlateVisibility::Visible);
	e6_BLACKMOVES->SetVisibility(ESlateVisibility::Visible);

	BackgroundBlur_2->SetVisibility(ESlateVisibility::Visible);
}

void ULondonSystemUserWidget::Stepe6c5ToSelectVariationClicked()
{
	LondonSystemBasic->SetVisibility(ESlateVisibility::Hidden);
	SelectVariation->SetVisibility(ESlateVisibility::Visible);
	Withg6->SetVisibility(ESlateVisibility::Hidden);
	Withe6c5->SetVisibility(ESlateVisibility::Hidden);
	Withe6->SetVisibility(ESlateVisibility::Hidden);

	Stepg6Variation->SetVisibility(ESlateVisibility::Visible);
	Stepe6Variation->SetVisibility(ESlateVisibility::Visible);
	Stepe6c5Variation->SetVisibility(ESlateVisibility::Visible);
	StepSelectVariationToThree->SetVisibility(ESlateVisibility::Visible);
	StepVariationToMainMenu->SetVisibility(ESlateVisibility::Visible);
	LSBG_Variation->SetVisibility(ESlateVisibility::Visible);
	SelectVariationTxt->SetVisibility(ESlateVisibility::Visible);

	BackgroundBlur_0->SetVisibility(ESlateVisibility::Visible);
}
