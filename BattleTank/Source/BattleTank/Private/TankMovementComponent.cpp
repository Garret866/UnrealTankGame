// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"


void UTankMovementComponent::IntendMoveForward(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend Move Forward throw: %f"),Throw);
}

void UTankMovementComponent::IntendMoveBackward(float Throw)
{
	UE_LOG(LogTemp, Warning, TEXT("Intend Move Backward throw: %f"), Throw);
}
