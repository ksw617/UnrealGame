// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class UNREALGAME_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
		class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere)
		class UCameraComponent* Camera;
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

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	void MoveForwardBackward(float value);
	void MoveLeftRight(float value);
	void LookLeftRight(float value);
	void Attack();

	UFUNCTION()
		void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);

public:
	float GetX() { return X; }
	float GetY() { return Y; }


};
