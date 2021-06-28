// King's Gambit by Jonathan Mui and Kishor Kumar

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PlayModeUserWidget.h"
#include "PlayModeHUD.generated.h"

/**
 * 
 */
UCLASS()
class KINGSGAMBIT_API APlayModeHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	APlayModeHUD();

	virtual void BeginPlay() override;

	//Class of user widget
	UPROPERTY(EditAnywhere, Category = "Widgets")
	TSubclassOf<class UUserWidget> WidgetClass; //set in blueprints

	//Pointer to created user widget
	class UPlayModeUserWidget* Widget;
};
