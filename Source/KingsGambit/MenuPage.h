// King's Gambit by Jonathan Mui and Kishor Kumar

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "MenuPage.generated.h"

class APlayerController;

/**
 * Menu GUI itself is programmed in blueprint
 */
UCLASS()
class KINGSGAMBIT_API AMenuPage : public ALevelScriptActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> MenuScreenClass;

	APlayerController* PlayerController;
	
};
