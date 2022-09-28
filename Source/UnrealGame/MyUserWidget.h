// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"

UCLASS()
class UNREALGAME_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void BindHp(class UMyActorComponent* ActorComp);
	void UpdateHp();

private:
	UPROPERTY()
	class UMyActorComponent* MyActorComp;

	UPROPERTY(meta = (BindWidget))
		class UProgressBar* PB_HpBar;
};
