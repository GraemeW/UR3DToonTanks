// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Tank.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(ProjectileName);
	RootComponent = ProjectileMesh;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(ProjectileMovementName);
	ProjectileMovement->InitialSpeed = InitialSpeed;
	ProjectileMovement->MaxSpeed = MaxSpeed;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ATank* tank = Cast<ATank>(OtherActor);
	UE_LOG(LogTemp, Display, TEXT("Hit Component: %s"), *HitComp->GetName());
	UE_LOG(LogTemp, Display, TEXT("Other Actor: %s"), *OtherActor->GetName());
	UE_LOG(LogTemp, Display, TEXT("Other Component: %s"), *OtherComp->GetName());

	if (tank != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank Hit"));
	}
	this->Destroy();
}
