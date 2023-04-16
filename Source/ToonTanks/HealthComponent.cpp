// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHP = InitialHP;
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::DamageTaken);
}

// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* Instigator, AActor* DamageCauser)
{
	CurrentHP += -Damage;
	if (CurrentHP > MaxHP) { CurrentHP = MaxHP; }
	UE_LOG(LogTemp, Display, TEXT("%s hit - current HP: %f"), *(GetOwner()->GetName()), CurrentHP);

	if (CurrentHP <= 0)
	{
		KillSelf();
	}
}

void UHealthComponent::KillSelf()
{
	UE_LOG(LogTemp, Display, TEXT("Destroying %s"), *(GetOwner()->GetName()));
	GetOwner()->Destroy();
}
