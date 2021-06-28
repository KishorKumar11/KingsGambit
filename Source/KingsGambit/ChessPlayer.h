// King's Gambit by Jonathan Mui and Kishor Kumar

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayModeController.h"
#include "ChessPlayer.generated.h"

UCLASS()
class KINGSGAMBIT_API AChessPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AChessPlayer();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Methods:
	UFUNCTION(BlueprintCallable)
		FText GetName();

	UFUNCTION(BlueprintCallable)
		void SetName(FText PlayerName);

	UFUNCTION()
		FVector GetCameraPanDirection();

	//Properties:
	UPROPERTY(VisibleAnywhere)
		bool bIsWhite;

	UPROPERTY(VisibleAnywhere)
		APlayModeController* PlayerController;

	TArray<class AActorBase*> Pieces; //Stores all pieces that belong to player

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Camera Stuff")
		class USpringArmComponent* CameraSpringArm;

	UPROPERTY(EditAnywhere, Category = "Camera Stuff")
		class UCameraComponent* Camera;

private:
	UPROPERTY(VisibleAnywhere)
		FText Name = FText::FromString("PlayerOne");
};
