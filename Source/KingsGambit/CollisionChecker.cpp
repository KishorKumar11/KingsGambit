// King's Gambit by Jonathan Mui and Kishor Kumar


#include "CollisionChecker.h"
#include "Components/BoxComponent.h"

// Sets default values
ACollisionChecker::ACollisionChecker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Create box component and assign it as root component
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	RootComponent = CollisionBox;
	CollisionBox->InitBoxExtent(CollisionBoxSize); //initialise box size to 100,100,100
}

// Called when the game starts or when spawned
void ACollisionChecker::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollisionChecker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

