// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	//do some stuff at begin play
	Super::BeginPlay();
	auto possessedTank = GetControlledTank();
	auto playerTank = GetPlayerTank();
	if (possessedTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank Ai controller possesing %s"), *possessedTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank AI controller not possesing tank"));
	}

	if (playerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank Ai controller found player %s"), *playerTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank AI controller not finding player"));
	}

}

ATank* ATankAIController::GetPlayerTank() const
{
	ATank* PlayerTank = nullptr;
	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	return PlayerTank;
}

ATank* ATankAIController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());

}