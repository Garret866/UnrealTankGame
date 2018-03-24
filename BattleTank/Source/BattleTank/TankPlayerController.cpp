// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Runtime/Engine/Classes/Engine/World.h"

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

	FVector HitLocation; //Out param
	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
	//this function raycasts from playercontroller.getcamera.center
	//checks if it hit something on the visibility channel
	//returns true and changes the & param with hit point if true
	//else false

	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		if (GetLookVectorHitLocation(LookDirection, OutHitLocation))
		{
			return true;
		}
		return false;
	}
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector AimLocation; //discarded
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, AimLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	//returns where in the world we hit, returns fvector(0) if not hit anything.
	FHitResult HitResult;
	FCollisionQueryParams ColQueryParams(FName(TEXT("AimingTrace")), false);
	auto StartLocation = PlayerCameraManager->GetCameraLocation();

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, StartLocation + LookDirection*LineTraceRange,
		ECollisionChannel::ECC_Visibility, ColQueryParams))
	{
		HitLocation = HitResult.ImpactPoint;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}


