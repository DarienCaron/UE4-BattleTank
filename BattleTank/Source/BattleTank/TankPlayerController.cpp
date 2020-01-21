// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ATank* temp = GetControlledTank();

	if (temp != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("We got a tank!"));
	}

}

void ATankPlayerController::Tick(float deltatime)
{
	Super::Tick(deltatime);

	AimTowardsCrosshair();
	
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}


	FVector HitLocation;

	bool didHit = GetSightHitLocation(HitLocation);

	if (didHit)
	{
		GetControlledTank()->AimAt(HitLocation);
	}

	// 
}

bool ATankPlayerController::GetSightHitLocation(FVector& out_location) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);


	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	FVector LookDirection;

	
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		
		if (GetLookHitVectorLocation(LookDirection, out_location))
		{
			return true;
		}


	}


	return false;


}

bool ATankPlayerController::GetLookDirection(FVector2D screenlocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	

	return DeprojectScreenPositionToWorld(screenlocation.X, screenlocation.Y, CameraWorldLocation, LookDirection);
	
	
	

}

bool ATankPlayerController::GetLookHitVectorLocation(FVector lookDir, FVector& outHit) const
{
	FHitResult hit;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (lookDir * MaxShotRange);

	if (GetWorld()->LineTraceSingleByChannel(hit, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		outHit = hit.Location;
		return true;
	}

	return false;
}
