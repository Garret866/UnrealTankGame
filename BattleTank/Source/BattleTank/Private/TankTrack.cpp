// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"



void UTankTrack::SetThrottle(float Throttle)
{
	//TODO clamp actual throttle value so that player cant go over 1

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied,ForceLocation);
}
