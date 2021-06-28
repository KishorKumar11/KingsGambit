// King's Gambit by Jonathan Mui and Kishor Kumar


#include "PlayModeHUD.h"
#include "PlayModeController.h"

APlayModeHUD::APlayModeHUD()
{
	//static ConstructorHelpers::FClassFinder<UPlayModeUserWidget> WidgetAsset(TEXT("WidgetBlueprint'/Game/Blueprints/UI/BP_PlayModeHUD'"));
	//if (WidgetAsset.Succeeded()) {
	//	WidgetClass = WidgetAsset.Class;
	//}
	//else {
	//	UE_LOG(LogTemp, Warning, TEXT("FAILED TO LOAD HUD BLUEPRINT!"));
	//}
}

void APlayModeHUD::BeginPlay() 
{
	Super::BeginPlay();

	if (WidgetClass) {
		Widget = CreateWidget<UPlayModeUserWidget>(GetWorld(), WidgetClass);
		if (Widget) {
			Widget->AddToViewport();
		}
	}
}