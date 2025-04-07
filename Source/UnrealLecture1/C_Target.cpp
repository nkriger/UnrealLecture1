// Fill out your copyright notice in the Description page of Project Settings.


#include "C_Target.h"

#include "UnrealLecture1Projectile.h"
#include "Components/SphereComponent.h"

// Sets default values
AC_Target::AC_Target()
{
     _TargetCollision = CreateDefaultSubobject<USphereComponent>(TEXT("TargetCollision"));
     _TargetCollision->SetupAttachment(RootComponent);
     _TargetCollision->OnComponentBeginOverlap.AddDynamic(this, &AC_Target::OnTargetCollisionBeginOverlap);
     _Timeshit = 0;




}

UFUNCTION()
void AC_Target::OnTargetCollisionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	 AUnrealLecture1Projectile* otherProjectile = Cast<AUnrealLecture1Projectile>(OtherActor);
     if (otherProjectile != nullptr) {
         _Timeshit++;
         if (_Timeshit >= 10) {
			 TenHitVisual();
		 }

     }
}

UFUNCTION()
void AC_Target::TenHitVisual() {

}

