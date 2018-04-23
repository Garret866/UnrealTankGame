// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	//move Turret right amount this frame
	//given max Rotation speed, and the frame time
	auto RotationChange = FMath::Clamp<float>(RelativeSpeed, -1, 1) * MaxDegreesPerSeconds * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator( 0, RawNewElevation, 0));
}


