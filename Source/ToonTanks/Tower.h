// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()

	public:
		virtual void Tick(float DeltaTime) override;
		void HandleDestruction();

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

	private:
		// Cached References
		class ATank* PlayerTank;

		// Properties
		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Movement")
		float TargetingDistanceThreshold = 1000.f;
		
		UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Movement")
		float FirePeriod = 2.f; // Seconds

		// Private Methods
		bool IsPlayerInRange(FVector& PlayerPosition);
		void CheckFireCondition();

		// State
		FTimerHandle FireRateTimerHandle;
		bool InRange = false;
	
};
