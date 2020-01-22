// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "..\Public\Tank.h"

// Sets default values
ATank::ATank()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	//  No need to protect pointers
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aim Component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector hitLocation)
{
	TankAimingComponent->AimAt(hitLocation, LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel* barrelSet)
{
	TankAimingComponent->SetBarrel(barrelSet);
}

