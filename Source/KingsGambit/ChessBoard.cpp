// King's Gambit by Jonathan Mui and Kishor Kumar


#include "ChessBoard.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AChessBoard::AChessBoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Create BoxComponent and make root component box component. Initialise location of component to (0,0,0)
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	RootComponent = BoxComponent;
	BoxComponent->InitBoxExtent(FVector(0, 0, 0));

	//Set materials
	//White Material
	static ConstructorHelpers::FObjectFinder<UMaterial> Material1(TEXT("Material'/Game/TexturesAndMaterials/WhiteMarble_Mat.WhiteMarble_Mat'"));
	if (Material1.Object != NULL) {
		WhiteMaterial = Material1.Object;
	}
	//Black Material
	static ConstructorHelpers::FObjectFinder<UMaterial> Material2(TEXT("Material'/Game/TexturesAndMaterials/DarkWood_Mat.DarkWood_Mat'"));
	if (Material2.Object != NULL) {
		BlackMaterial = Material2.Object;
	}
	//Highlighted Material
	static ConstructorHelpers::FObjectFinder<UMaterial> Material3(TEXT("Material'/Game/TexturesAndMaterials/M_SelectedMaterial.M_SelectedMaterial'"));
	if (Material3.Object != NULL) {
		HighlightedMaterial = Material3.Object;
	}

	//Creation of Board Grids
	for (int32 index = 0; index < 64; ++index) {
		//Set Coordinates (using 400x400 floor mesh)
		int32 XCoord = (index / 8) * 400;
		int32 YCoord = (index % 8) * 400;

		//Adding static meshes (floor) to component grid by grid
		GridSquares.Add(CreateDefaultSubobject<UStaticMeshComponent>(*FString("Mesh" + FString::FromInt(index))));
		GridSquares[index]->SetupAttachment(BoxComponent); //Attach each grid to root component

		//Retrieve floor asset
		static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("StaticMesh'/Game/Meshes/GridMesh.GridMesh'"));
		
		if (StaticMeshAsset.Succeeded()) {
			//Set floor asset to static mesh
			GridSquares[index]->SetStaticMesh(StaticMeshAsset.Object);
			//Set coordinates for each board grid
			GridSquares[index]->SetRelativeLocation(FVector(XCoord, YCoord, 0));
		}		
	}
}

// Called when the game starts or when spawned
void AChessBoard::BeginPlay()
{
	Super::BeginPlay();

	//Set Materials to grid
	for (int32 index = 0; index < 64; ++index) {
		int32 Horizontal = (index / 8) % 2;
		int32 Vertical = (index % 8) % 2;
		if (Horizontal != Vertical) {
			GridSquares[index]->SetMaterial(0, WhiteMaterial);
			DefaultMaterial = WhiteMaterial;
		}
		else {
			GridSquares[index]->SetMaterial(0, BlackMaterial);
			DefaultMaterial = BlackMaterial;
		}
	}
}

// Called every frame
void AChessBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChessBoard::HighlightGrid(UStaticMeshComponent* Grid)
{
	Grid->SetMaterial(0, HighlightedMaterial);
}

