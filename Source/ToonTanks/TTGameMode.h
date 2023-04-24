// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TTGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATTGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	void ActorDied(AActor* DeadActor);

protected:
	virtual void BeginPlay() override;

private:
	// Parameters
	UPROPERTY(EditAnywhere, Category = "GameStart")
	float StartDelay = 3.f;
	
	// Methods
	void HandleGameStart();

	// State
	class ATank* Tank;
	class ATTPlayerController* TTPlayerController;
};
