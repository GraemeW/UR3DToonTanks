// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Hook-Ups
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "PawnHookups")
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "PawnHookups")
	class UProjectileMovementComponent* ProjectileMovement;

	// Names
	TCHAR* ProjectileName = TEXT("Projectile");
	TCHAR* ProjectileMovementName = TEXT("ProjectileMovement");

	// Parameters
	UPROPERTY(EditAnywhere, Category = "Movement")
	float InitialSpeed = 3000.0f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MaxSpeed = 5000.0f;

	// State
	float CurrentDamage = 0.0f;

	// Private Methods
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Public Methods
	void SetCurrentDamage(float Damage);

};
