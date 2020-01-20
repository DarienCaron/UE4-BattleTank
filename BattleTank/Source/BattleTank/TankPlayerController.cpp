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
