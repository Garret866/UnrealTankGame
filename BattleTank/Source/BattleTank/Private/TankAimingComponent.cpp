// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "TankBarrel.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Engine/World.h" 
#include "TankTurret.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true; //TODO should we really tick here?

	// ...
}


void UTankAimingComponent::AimAt(FVector WorldSpaceAim, float LaunchSpeed)
{
	//rotate barrel and turret to target
	if (Turret && Barrel)
	{
		FVector OutLaunchVelocity;
		FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
		//if we can shoot what we are aiming at (if there is no aim ,e.g sky, it wont even get to this func from tankPlayerController):
		if (UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, WorldSpaceAim,
			LaunchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace))
		{
			auto AimDirection = OutLaunchVelocity.GetSafeNormal();
			MoveBarrelTowards(AimDirection);
			MoveTurretTowards(AimDirection);
			auto Time = GetWorld()->GetTimeSeconds();
			//UE_LOG(LogTemp, Warning, TEXT("%f Barrel-Elevate Called %s"), Time, *GetOwner()->GetName());
		}
		else
		{
			auto Time = GetWorld()->GetTimeSeconds();
			UE_LOG(LogTemp, Warning, TEXT("%f target out of range %s"), Time, *GetOwner()->GetName());
		}
	}
	
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret * TurretToSet)
{
	Turret = TurretToSet;
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	//Work out difference between current barrel rotation and aimdirection
	auto BarrelRotation = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotation;
	Barrel->Elevate(DeltaRotator.Pitch);

}

void UTankAimingComponent::MoveTurretTowards(FVector AimDirection)
{
	//Work out difference between current turret rotation and aimdirection
	auto TurretRotation = Turret->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator.Yaw - TurretRotation.Yaw;
	UE_LOG(LogTemp, Warning, TEXT("aimYaw: %f, turretNowYaw: %f, DeltaYaw: %f"), AimAsRotator.Yaw, TurretRotation.Yaw, DeltaRotator);
	Turret->Rotate(DeltaRotator);
}

