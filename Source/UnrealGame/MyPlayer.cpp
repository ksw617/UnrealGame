// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

AMyPlayer::AMyPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);

	SpringArm->TargetArmLength = 500.f;
	SpringArm->SetRelativeRotation(FRotator(-35.f, 0.f, 0.f));

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SM(TEXT("SkeletalMesh'/Game/PolygonDungeonRealms/Meshes/Characters/SK_BR_Chr_Demon_01.SK_BR_Chr_Demon_01'"));

	if (SM.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SM.Object);
		GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));
	}

}

void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
}

void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForwardBackward"), this, &AMyPlayer::MoveForwardBackward);
	PlayerInputComponent->BindAxis(TEXT("MoveLeftRight"), this, &AMyPlayer::MoveLeftRight);
	PlayerInputComponent->BindAxis(TEXT("LookLeftRight"), this, &AMyPlayer::LookLeftRight);

	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &AMyPlayer::Jump);
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &AMyPlayer::Attack);

}

void AMyPlayer::MoveForwardBackward(float value)
{
	Y = value;
	AddMovementInput(GetActorForwardVector(), value);
}

void AMyPlayer::MoveLeftRight(float value)
{
	X = value;
	AddMovementInput(GetActorRightVector(), value);
}

void AMyPlayer::LookLeftRight(float value)
{
	AddControllerYawInput(value);
}

