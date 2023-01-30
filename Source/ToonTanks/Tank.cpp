// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"

ATank::ATank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(SpringArmName);
	SpringArm->SetupAttachment(RootComponent);

	PawnCamera = CreateDefaultSubobject<UCameraComponent>(CameraName);
	PawnCamera->SetupAttachment(SpringArm);
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
}

void ATank::Move(float Value)
{
	UE_LOG(LogTemp, Display, TEXT("Movement registered as: %f"), Value);
}
