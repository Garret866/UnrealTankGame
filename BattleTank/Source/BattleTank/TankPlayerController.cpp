// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	//do some stuff at begin play
	Super::BeginPlay();
	auto possessedTank = GetControlledTank();
	//check proper player tank possession
	if (possessedTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("player controller possesing %s"), *possessedTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("pplayer controller not possesing tank ?"));
	}
	//activate ticking
	PrimaryActorTick.bCanEverTick = true;
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	//get world location through linetrace though the crosshair
	//if it hits the landscape then the controlled tank should aim at that point

}

