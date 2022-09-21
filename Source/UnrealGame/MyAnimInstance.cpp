// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "MyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

UMyAnimInstance::UMyAnimInstance()
{
	ConstructorHelpers::FObjectFinder<UAnimMontage> AM(TEXT("AnimMontage'/Game/Animation/Attack_Montage.Attack_Montage'"));
	if (AM.Succeeded())
	{
		AttackMontage = AM.Object;
	}
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (IsValid(Pawn))
	{
		Speed = Pawn->GetVelocity().Size();

		auto Character = Cast<AMyCharacter>(Pawn);

		if (IsValid(Character))
		{
			 Vertical = Character->GetY();
			 Horizontal = Character->GetX();

			 IsFalling = Character->GetMovementComponent()->IsFalling();
		}
	}
}

void UMyAnimInstance::PlayAttackAnimation(int32 index)
{
	Montage_Play(AttackMontage, 1.f);
	FName AniName = FName(*FString::Printf(TEXT("Attack_%d"), index));
	Montage_JumpToSection(AniName, AttackMontage);
}

void UMyAnimInstance::AnimNotify_Hit()
{
	//UE_LOG(LogTemp, Log, TEXT("Hit"));
}
