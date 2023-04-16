// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOONTANKS_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	// Properties
	UPROPERTY(EditAnywhere, Category = "Parameters")
	float InitialHP = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Parameters")
	float MaxHP = 200.0f;

	// State
	float CurrentHP = 100.0f; // Overridden to InitialHealth on BeginPlay()

	// Methods
	UFUNCTION()
	void DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType, class AController* Instigator, AActor* DamageCauser);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Public Methods
	void AdjustHP(float points);
	void KillSelf();
	
		
};
