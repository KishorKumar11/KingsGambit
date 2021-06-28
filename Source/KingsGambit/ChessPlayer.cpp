// King's Gambit by Jonathan Mui and Kishor Kumar


#include "ChessPlayer.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AChessPlayer::AChessPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	CameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	CameraSpringArm->SetupAttachment(RootComponent);
	CameraSpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(-60.0f, 0.0f, 0.0f));
	CameraSpringArm->bDoCollisionTest = false;
	CameraSpringArm->TargetArmLength = 400.f;
	CameraSpringArm->bEnableCameraLag = true;
	CameraSpringArm->CameraLagSpeed = 3.0f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	Camera->SetupAttachment(CameraSpringArm, USpringArmComponent::SocketName);

	//Take control of the default Player
	//Determines which PlayerController, if any, should automatically possess the pawn when the level starts or when the pawn is spawned.
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AChessPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	PlayerController = Cast<APlayModeController>(GetController());
}

// Called every frame
void AChessPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AChessPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

FText AChessPlayer::GetName()
{
	return Name;
}

void AChessPlayer::SetName(FText PlayerName)
{
	Name = PlayerName;
}

FVector AChessPlayer::GetCameraPanDirection()
{
	// Variable to hold mouse position
	float MousePositionX;
	float MousePositionY;
	float CameraDirectionX = 0;
	float CameraDirectionY = 0;

	PlayerController->GetMousePosition(MousePositionX, MousePositionY);
	if (MousePositionX == 0)
	{
		CameraDirectionY = -1;
	}
	return FVector(CameraDirectionX, CameraDirectionY, 0);
}