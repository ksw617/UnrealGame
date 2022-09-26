// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

UMyGameInstance::UMyGameInstance()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> DATA(TEXT("DataTable'/Game/Data/CharacterDataTable.CharacterDataTable'"));
	
	if (DATA.Succeeded())
	{
		CharacterDataTable = DATA.Object;
	}
}


void UMyGameInstance::Init()
{
	Super::Init();
	UE_LOG(LogTemp, Warning, TEXT("Character Data : %d"), GetCharacterData(2)->MaxHp);
}

FMyCharacterData* UMyGameInstance::GetCharacterData(int32 Level)
{
	FName RowName = FName(*FString::Printf(TEXT("Lv%d"), Level));
	return CharacterDataTable->FindRow<FMyCharacterData>(RowName, TEXT(""));
}
