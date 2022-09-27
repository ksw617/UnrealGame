// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class UNREALGAME_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

protected:

	UPROPERTY(VisibleAnywhere)
		float X;
	UPROPERTY(VisibleAnywhere)
		float Y;
	UPROPERTY()
		class UMyAnimInstance* AnimInstance;
	UPROPERTY(VisibleAnywhere)
		bool IsAttacking = false;
	UPROPERTY()
		int32 AttackIndex = 0;
	UPROPERTY(VisibleAnywhere)
		class UMyActorComponent* MyActorComponent;
	UPROPERTY(VisibleAnywhere)
		class UWidgetComponent* HpBar;

public:
	AMyCharacter();
protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
public:
	void Attack();
	void OnHit();
public:
	UFUNCTION()
		void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);

public:
	float GetX() { return X; }
	float GetY() { return Y; }


};
