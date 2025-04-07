// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "C_Target.generated.h"

class USphereComponent;

UCLASS(Abstract)
class UNREALLECTURE1_API AC_Target : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly)
	USphereComponent* _TargetCollision;
	int _Timeshit;
	
public:	
	// Sets default values for this actor's properties
	AC_Target();
	UFUNCTION()
	void OnTargetCollisionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void TenHitVisual();

};
