// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	//do some stuff at begin play
	Super::BeginPlay();
	ControlledTank = GetControlledTank();
	PlayersTank = GetPlayerTank();
	//Log controllers possessing tanks:
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank Ai controller possesing %s"), *ControlledTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank AI controller not possesing tank"));
	}
	if (PlayersTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank Ai controller found player %s"), *PlayersTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank AI controller not finding player"));
	}
	PrimaryActorTick.bCanEverTick = true;
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!PlayersTank || !ControlledTank) { return; }
	//move towards the player
	//aim towards player
	ControlledTank->AimAt(PlayersTank->GetTargetLocation(ControlledTank)); //targetLocation is more optimal than location, but subject to change
	//fire when ready
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}