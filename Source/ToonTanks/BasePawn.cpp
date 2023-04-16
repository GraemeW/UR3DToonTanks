// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Projectile.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "HealthComponent.h"

// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(CapsuleName);
	RootComponent = CapsuleComp;
	HealthComp = CreateDefaultSubobject<UHealthComponent>(HealthName);

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(BaseName);
	BaseMesh->SetupAttachment(CapsuleComp);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TurretName);
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(ProjectileSpawnPointName);
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);
}

// Called when the game starts or when spawned
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
}

void ABasePawn::RotateTurret(FVector LookAtTarget, float DeltaTime)
{
	FVector ToTarget = (LookAtTarget - TurretMesh->GetComponentLocation());
	FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);

	TurretMesh->SetWorldRotation(FMath::RInterpTo(TurretMesh->GetComponentRotation(), LookAtRotation, DeltaTime, TurretLookAtSpeed));
}

void ABasePawn::Fire()
{
	if (ProjectileClass == nullptr) { return; }

	AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, ProjectileSpawnPoint->GetComponentLocation(), TurretMesh->GetComponentRotation());
	Projectile->SetOwner(this);
	Projectile->SetCurrentDamage(Damage);

	// Debug:
	// DrawDebugSphere(GetWorld(), ProjectileSpawnPoint->GetComponentLocation(), 50.f, 16, FColor::Red, true, 5.f);
}

// Called every frame
void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

