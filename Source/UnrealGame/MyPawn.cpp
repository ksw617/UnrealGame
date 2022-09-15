// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));

	RootComponent = Mesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("StaticMesh'/Game/PolygonDungeonRealms/Meshes/Props/SM_Prop_Barrel_01.SM_Prop_Barrel_01'"));

	if (StaticMesh.Succeeded())
	{
		Mesh->SetStaticMesh(StaticMesh.Object);
	}

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();

	

}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("UPDown"), this, &AMyPawn::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AMyPawn::LeftRight);

}

void AMyPawn::UpDown(float value)
{

	AddMovementInput(GetActorForwardVector(), value);
}

void AMyPawn::LeftRight(float value)
{
	AddMovementInput(GetActorRightVector(), value);
}

