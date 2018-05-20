// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"
//forward dclr:
class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

protected:
	ATank* ControlledTank = nullptr;
	ATank* PlayersTank = nullptr;
	
private:
	//how close can the ai tank get
	float AcceptanceRadius = 3000; //assuming cm
};
