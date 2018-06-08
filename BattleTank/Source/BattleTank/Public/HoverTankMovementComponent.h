// Copyright NobodyEntertainment inc

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "HoverTankMovementComponent.generated.h"

class UHoverPlate;

/**
 * manages the array of Hoverplates on the tank, and also the tank itself (max speed, and staying on slopes?)
 * translates player input to hoverplate commands
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UHoverTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	//UFUNCTION(BlueprintCallable, Category = "Input")
	//	void IntendMoveLinear(float ThrowForward,float ThrowRight);
	//UFUNCTION(BlueprintCallable, Category = "Input")
		void IntendTurnRight(float Throw);

	//UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialize(UHoverPlate* LeftPlateToSet, UHoverPlate* RightPlateToSet, TArray<UHoverPlate*> SecondaryHoverPlates);


private:
	//call from the pathfinding logic by the ai controllers;
	//void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

	UHoverPlate* LeftMainPlate = nullptr;
	UHoverPlate* RightMainPlate = nullptr;
	TArray<UHoverPlate*> SecondaryHoverPlates;
	
};
