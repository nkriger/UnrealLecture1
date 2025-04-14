// Fill out your copyright notice in the Description page of Project Settings.


#include "C_HealthComponent.h"

// Sets default values for this component's properties
UC_HealthComponent::UC_HealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	//PrimaryComponentTick.bCanEverTick = true;

	// ...

	_maxHealth = 100.0f;
}


// Called when the game starts
void UC_HealthComponent::BeginPlay()
{
	Super::BeginPlay();
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UC_HealthComponent::DamageTaken);

	// ...
	_currentHealth = _maxHealth;
}

void UC_HealthComponent::DamageTaken(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{

	_currentHealth = FMath::Max(_currentHealth - Damage, 0.0f);
	//_currentHealth -= Damage;

	OnComponentDamaged.Broadcast(InstigatedBy, Damage, _currentHealth);

}

/*

// Called every frame
void UC_HealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
*/

