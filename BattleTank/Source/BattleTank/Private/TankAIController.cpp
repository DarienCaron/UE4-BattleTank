// Fill out your copyright notice in the Description page of Project Settings.


#include "..\Public\TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* temp = GetControlledTank();

	if (temp != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("We got an AI tank!"));
	}


	auto p = GetPlayerTank();

	if (p != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("I found the player tank! %s"), *p->GetName());
	}

}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto player = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (player != nullptr)
	{
		return Cast<ATank>(player);
	}

	return nullptr;

}
