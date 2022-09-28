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
			MaxHp = CharacterData->MaxHp;
			Hp = MaxHp;
		}
	}

}

void UMyActorComponent::OnDamaged(float DamageAmount)
{
	int32 NewHp = Hp - DamageAmount;
	SetHp(NewHp);
}

void UMyActorComponent::SetHp(int32 NewHp)
{

	Hp = NewHp;
	if (Hp < 0)
	{
		Hp = 0;
	}




	OnHpChanged.Broadcast();
}

float UMyActorComponent::GetHpRatio()
{
	// 0 / 100 == 0
	if (MaxHp == 0 || Hp == 0)
	{
		return 0.f;
	}

	//100 / 100 == 1.f
	//90 / 100 == 0.9f
	//10 / 100 == 0.1f
	return (float)Hp / (float)MaxHp;
}

