// King's Gambit by Jonathan Mui and Kishor Kumar


#include "PlayMode.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

// Called when the game starts or when spawned
void APlayMode::BeginPlay()
{
	Super::BeginPlay();
	PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PlayerController == nullptr) { return; }
	UUserWidget* PlayModeHUD = CreateWidget(PlayerController, PlayModeHUDClass);

	if (PlayModeHUD != nullptr) {
		PlayModeHUD->AddToViewport();
	}
	PlayerController->SetShowMouseCursor(true);
}
