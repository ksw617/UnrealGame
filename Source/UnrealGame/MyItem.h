// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyItem.generated.h"

UCLASS()
class UNREALGAME_API AMyItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyItem();
private:
	UFUNCTION()
		void OnCharacterOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	//BeginPlay 호출전 호출
	virtual void PostInitProperties() override;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* Item;
	UPROPERTY(VisibleAnywhere)
		class UBoxComponent* Trigger;


};
