// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "C_HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FComponentDeadSigniture, AController*, causer);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FComponentDamageSigniture, AController*, causer, float, damage, float, newHealth);



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )


class UNREALLECTURE1_API UC_HealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UC_HealthComponent();

	UPROPERTY(BlueprintAssignable) FComponentDeadSigniture OnComponentDead;
	UPROPERTY(BlueprintAssignable) FComponentDamageSigniture OnComponentDamaged;

protected:
	// Called when the game starts
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere) float _currentHealth;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) float _maxHealth;
	virtual void BeginPlay() override;

	UFUNCTION() void DamageTaken(AActor* damagedActor, float damage, const UDamageType* damageType, AController* causer, AActor* damageCauser);

public:	
	// Called every frame
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
