// Fill out your copyright notice in the Description page of Project Settings.


#include "TTGameMode.h"
#include "TTPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "Tower.h"

void ATTGameMode::ActorDied(AActor* DeadActor)
{
	if (DeadActor == Tank)
	{
		Tank->HandleDestruction();
		if (TTPlayerController)
		{
			TTPlayerController->SetPlayerEnabledState(false);
		}
	}
	else if (ATower* DestroyedTower = Cast<ATower>(DeadActor))
	{
		DestroyedTower->HandleDestruction();
	}
}

void ATTGameMode::BeginPlay()
{
	Super::BeginPlay();

	HandleGameStart();
}

void ATTGameMode::HandleGameStart()
{
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	TTPlayerController = Cast<ATTPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

	StartGame();

	if (TTPlayerController)
	{
		TTPlayerController->SetPlayerEnabledState(false);
	}
	FTimerHandle PlayerEnableTimerHandle;
	FTimerDelegate PlayerEnableTimerDelegate = FTimerDelegate::CreateUObject(TTPlayerController, &ATTPlayerController::SetPlayerEnabledState, true);
	GetWorldTimerManager().SetTimer(PlayerEnableTimerHandle, PlayerEnableTimerDelegate, StartDelay, false);
}
