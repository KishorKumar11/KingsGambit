// King's Gambit by Jonathan Mui and Kishor Kumar


#include "ActorBase.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/Material.h"

// Sets default values
AActorBase::AActorBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Create Static mesh and assign as root
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMesh;

	StaticMesh->SetCollisionProfileName(TEXT("Pawn"));
	StaticMesh->SetSimulatePhysics(true);

	// Set WhiteMaterial
	static ConstructorHelpers::FObjectFinder<UMaterial> GetWhiteMaterial(TEXT("Material'/Game/TexturesAndMaterials/M_LightMaterial.M_LightMaterial'"));
	if (GetWhiteMaterial.Succeeded())
	{
		WhiteMaterial = GetWhiteMaterial.Object;
	}

	// Set BlackMaterial
	static ConstructorHelpers::FObjectFinder<UMaterial> GetBlackMaterial(TEXT("Material'/Game/TexturesAndMaterials/M_DarkMaterial.M_DarkMaterial'"));
	if (GetBlackMaterial.Succeeded())
	{
		BlackMaterial = GetBlackMaterial.Object;
	}

	//Set SelectedMaterial
	static ConstructorHelpers::FObjectFinder<UMaterial> GetSelectedMaterial(TEXT("Material'/Game/TexturesAndMaterials/M_SelectedMaterial.M_SelectedMaterial'"));
	if (GetSelectedMaterial.Succeeded())
	{
		HighlightedMaterial = GetSelectedMaterial.Object;
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> GetEliminatedMaterial(TEXT("Material'/Game/TexturesAndMaterials/M_EliminateMaterial.M_EliminateMaterial'"));
	if (GetEliminatedMaterial.Succeeded())
	{
		EliminateMaterial = GetEliminatedMaterial.Object;
	}
}

// Called when the game starts or when spawned
void AActorBase::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AActorBase::SetDefaultMaterial()
{
	if (bIsWhite) {
		StaticMesh->SetMaterial(0, WhiteMaterial);
	}
	else {
		StaticMesh->SetMaterial(0, BlackMaterial);
	}
}

void AActorBase::SetHighlightedMaterial()
{
	StaticMesh->SetMaterial(0, HighlightedMaterial);
}

void AActorBase::SetEliminateMaterial()
{
	StaticMesh->SetMaterial(0, EliminateMaterial);
}

void AActorBase::MovePiece(FVector MoveTo)
{
	SetActorLocation(MoveTo);
}

void AActorBase::EliminatePiece()
{
	this->Destroy();
}

void AActorBase::DetectSelectableGrids(TArray<UStaticMeshComponent*>* SelectableGrids, TArray<UMaterial*>* DefaultMaterials)
{
	//Parent class for chess pieces. Specific chess pieces have specific sets of selectable grids
}
