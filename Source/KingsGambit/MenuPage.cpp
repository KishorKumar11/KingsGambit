// King's Gambit by Jonathan Mui and Kishor Kumar


#include "MenuPage.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

// Called when the game starts or when spawned
void AMenuPage::BeginPlay()
{
	Super::BeginPlay();
	PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PlayerController == nullptr) { return; }
	UUserWidget* MenuScreen = CreateWidget(PlayerController, MenuScreenClass);

	if (MenuScreen != nullptr) {
		MenuScreen->AddToViewport();
	}
	PlayerController->SetShowMouseCursor(true);
}