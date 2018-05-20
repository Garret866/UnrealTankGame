// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	//do some stuff at begin play
	Super::BeginPlay();
	ControlledTank = Cast<ATank>(GetPawn());
	PlayersTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	PrimaryActorTick.bCanEverTick = true;
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!PlayersTank || !ControlledTank) { return; }

	//move towards the player
	MoveToActor(PlayersTank, AcceptanceRadius); //TODO check radius is in cm

	//aim towards player
	ControlledTank->AimAt(PlayersTank->GetTargetLocation(ControlledTank)); //targetLocation is more optimal than location, but subject to change
	ControlledTank->Fire(); // TODO dont fire every frame
}
