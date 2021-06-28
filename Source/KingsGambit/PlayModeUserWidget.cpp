// King's Gambit by Jonathan Mui and Kishor Kumar


#include "PlayModeUserWidget.h"
#include "PlayModeController.h"
#include "ChessPlayer.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/Border.h"
#include "Components/VerticalBox.h"
#include "Components/CanvasPanel.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

//Acts like a beginplay for widgets
void UPlayModeUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	//Gets PlayMode Controller
	PlayModeController = Cast<APlayModeController>(UGameplayStatics::GetPlayerController(this, 0));

	PauseButton->OnClicked.AddUniqueDynamic(this, &UPlayModeUserWidget::PauseButtonClicked);
	ResumeButton->OnClicked.AddUniqueDynamic(this, &UPlayModeUserWidget::ResumeButtonClicked);
	MainMenuButton->OnClicked.AddUniqueDynamic(this, &UPlayModeUserWidget::MainMenuButtonClicked);
	QuitButton->OnClicked.AddUniqueDynamic(this, &UPlayModeUserWidget::QuitButtonClicked);

	ConfirmMoveButton->OnClicked.AddUniqueDynamic(this, &UPlayModeUserWidget::ConfirmMoveButtonClicked);
	CancelMoveButton->OnClicked.AddUniqueDynamic(this, &UPlayModeUserWidget::CancelMoveButtonClicked);

	OKButton->OnClicked.AddUniqueDynamic(this, &UPlayModeUserWidget::OKButtonClicked);

}

void UPlayModeUserWidget::NativeTick(const FGeometry& MyGeometry,
	float InDeltaTime)
{
	Super::NativeTick(MyGeometry,
		InDeltaTime);

}

void UPlayModeUserWidget::PauseButtonClicked()
{
	Super::PauseButtonClicked();
}

void UPlayModeUserWidget::ResumeButtonClicked()
{
	Super::ResumeButtonClicked();
}

void UPlayModeUserWidget::MainMenuButtonClicked()
{
	Super::MainMenuButtonClicked();
}

void UPlayModeUserWidget::QuitButtonClicked()
{
	Super::QuitButtonClicked();
}

void UPlayModeUserWidget::ConfirmMoveButtonClicked()
{
	PlayModeController->MakeMove();
	SetButtonVisibility(false);
}

void UPlayModeUserWidget::CancelMoveButtonClicked()
{
	PlayModeController->CancelMove();
	SetButtonVisibility(false);
}

void UPlayModeUserWidget::OKButtonClicked()
{
	UGameplayStatics::SetGamePaused(GetWorld(), false);
	UserGuide->SetVisibility(ESlateVisibility::Hidden);
	UserGuideInterface->SetVisibility(ESlateVisibility::Hidden);
}

void UPlayModeUserWidget::SetButtonVisibility(bool status)
{
	if (status) {
		ConfirmMoveWrapper->SetVisibility(ESlateVisibility::Visible);
	}
	else {
		ConfirmMoveWrapper->SetVisibility(ESlateVisibility::Hidden);
	}
}

FText UPlayModeUserWidget::GetCurrentPlayerName()
{
	if (PlayModeController) {
		return PlayModeController->GetCurrentPlayer()->GetName();
	}
	return FText::FromString("");
}

FText UPlayModeUserWidget::GetErrorMessage()
{
	if (PlayModeController) {
		return PlayModeController->ErrorMessage;
	}
	return FText::FromString("");
}
