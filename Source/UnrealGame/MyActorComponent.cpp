// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActorComponent.h"
#include "MyGameInstance.h"
#include "kismet/GameplayStatics.h"

UMyActorComponent::UMyActorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	bWantsInitializeComponent = true;
	Level = 1;

}

void UMyActorComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UMyActorComponent::InitializeComponent()
{
	Super::InitializeComponent();

	SetLevel(Level);
}

void UMyActorComponent::SetLevel(int32 NewLevel)
{
	auto MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (MyGameInstance)
	{
		auto CharacterData = MyGameInstance->GetCharacterData(NewLevel); 
		if (CharacterData)
		{
			Level = CharacterData->Level;
			Hp = CharacterData->MaxHp;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("Lv: %d, HP : %d"), Level, Hp);

}

void UMyActorComponent::OnDamaged(float DamageAmount)
{
	Hp -= DamageAmount;
	if (Hp < 0)
	{
		Hp = 0;
	}
	UE_LOG(LogTemp, Warning, TEXT("HP : %d"), Hp);
}

