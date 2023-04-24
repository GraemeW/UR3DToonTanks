// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

void ATower::BeginPlay()
{
	Super::BeginPlay();
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	PlayerTank = Cast<ATank>(PlayerPawn);

	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATower::CheckFireCondition, FirePeriod, true);
}

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (PlayerTank == nullptr) { return; }

	FVector PlayerPosition;
	InRange = IsPlayerInRange(PlayerPosition);
	if (!InRange) { return; }

	RotateTurret(PlayerPosition, DeltaTime);
}

void ATower::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}

void ATower::CheckFireCondition()
{
	if (!InRange) { return; }

	Fire();
}

bool ATower::IsPlayerInRange(FVector& PlayerPosition)
{
	if (PlayerTank == nullptr) { return false; }

	PlayerPosition = PlayerTank->GetActorLocation();
	float Distance = FVector::Dist(GetActorLocation(), PlayerPosition);
	return (Distance <= TargetingDistanceThreshold);
}
