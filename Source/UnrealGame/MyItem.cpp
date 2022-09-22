// Fill out your copyright notice in the Description page of Project Settings.


#include "MyItem.h"

// Sets default values
AMyItem::AMyItem()
{
	PrimaryActorTick.bCanEverTick = false;

	Item = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Item"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/PolygonDungeonRealms/Meshes/Weapons/SM_Wep_Axe_Large_05.SM_Wep_Axe_Large_05'"));
	if (SM.Succeeded())
	{
		Item->SetStaticMesh(SM.Object);
	}

	Item->SetCollisionProfileName(TEXT("NoCollision"));


}

// Called when the game starts or when spawned
void AMyItem::BeginPlay()
{
	Super::BeginPlay();
	
}


