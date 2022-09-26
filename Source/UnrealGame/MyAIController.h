// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyAIController.generated.h"

/**
 * 
 */
UCLASS()
class UNREALGAME_API AMyAIController : public AAIController
{
	GENERATED_BODY()
public:
	AMyAIController();
public:
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;
private:
	void RandomMove();
private:
	FTimerHandle TimerHandle;
	
};