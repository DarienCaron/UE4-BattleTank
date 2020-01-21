// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Public/Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()



public:

	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float deltatime) override;


private:

	void AimTowardsCrosshair();

	bool GetSightHitLocation(FVector& out_location) const;

	bool GetLookDirection(FVector2D screenlocation, FVector& LookDirection) const;

	bool GetLookHitVectorLocation(FVector lookDir, FVector& outHit) const;


private:

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.3333f;

	UPROPERTY(EditAnywhere)
	float MaxShotRange = 100000000.0f;
	
};
