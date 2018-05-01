// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public: 
	void Elevate(float RelativeSpeed); //-1 is max downwardMovement, and +1 is max up movement

private:
	UPROPERTY(EditAnywhere,Category = Setup)
		float MaxDegreesPerSeconds = 10;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationDegrees = -2;

	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationDegrees = 18;
};
