// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	//do some stuff at begin play
	Super::BeginPlay();
	auto possessedTank = GetControlledTank();
	if (possessedTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("player controller possesing %s"), *possessedTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("pplayer controller not possesing tank ?"));
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	
	return Cast<ATank>(GetPawn());
	
}

