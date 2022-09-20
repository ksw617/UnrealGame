// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class UNREALGAME_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
private:
	UPROPERTY(Category = Animation, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		float Speed;

	UPROPERTY(Category = Animation, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		float Horizontal;

	UPROPERTY(Category = Animation, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		float Vertical;

	UPROPERTY(Category = Animation, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		bool IsFalling;

	UPROPERTY(Category = Animation, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UAnimMontage* AttackMontage;
public:
	UMyAnimInstance();
public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
public:
	void PlayAttackAnimation();
};
