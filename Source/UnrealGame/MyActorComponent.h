// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyActorComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnHpChanged);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALGAME_API UMyActorComponent : public UActorComponent
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere, Category = Info, Meta = (AllowPrivateAccess = true))
		int32 Level;
	UPROPERTY(EditAnywhere, Category = Info, Meta = (AllowPrivateAccess = true))
		int32 Hp;
	UPROPERTY(EditAnywhere, Category = Info, Meta = (AllowPrivateAccess = true))
		int32 MaxHp;
public:	
	UMyActorComponent();

protected:
	virtual void BeginPlay() override;
	virtual void InitializeComponent() override;
public:	
	void SetLevel(int32 NewLevel);
	void OnDamaged(float DamageAmount);
	void SetHp(int32 NewHp);
	float GetHpRatio();


	int32 GetLevel() { return Level; }
	int32 GetHp() { return Hp; }
	int32 GetMaxHp() { return MaxHp; }

public:
	FOnHpChanged OnHpChanged;
};
