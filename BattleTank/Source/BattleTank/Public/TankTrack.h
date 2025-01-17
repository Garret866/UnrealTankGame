// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable,Category = Input)
	void SetThrottle(float Throttle);

	//Max Force Per Track in newtons
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float TrackMaxDrivingForce = 456000; //assume 40 ton tank and 0.25g accel
	
};
