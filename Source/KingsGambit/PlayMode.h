// King's Gambit by Jonathan Mui and Kishor Kumar

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "PlayMode.generated.h"

/**
 * 
 */
UCLASS()
class KINGSGAMBIT_API APlayMode : public ALevelScriptActor
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Widgets")
	TSubclassOf<UUserWidget> PlayModeHUDClass;

	APlayerController* PlayerController;
};
