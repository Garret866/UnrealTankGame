// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
class UTankBarrel; //Hold Barrel Properties and Elevate Method
class UTankTurret;
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	//Logs where the object is aiming at in the world
	void AimAt(FVector WorldSpaceAim,float LaunchSpeed);

	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void SetTurretReference(UTankTurret* TurretToSet); 
private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	void MoveBarrelTowards(FVector AimDirection);
	void MoveTurretTowards(FVector AimDirection);
};
