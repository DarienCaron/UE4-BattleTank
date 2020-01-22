// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "..\Public\TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector worldAimLocation, float launchSpeed)
{

	if (!TankBarrel)
	{
		return;
	}


	FVector OLauchVel;

	FVector StartLoc = TankBarrel->GetSocketLocation(FName("Projectile"));

	bool AimResult = UGameplayStatics::SuggestProjectileVelocity(this, OLauchVel, StartLoc, worldAimLocation, launchSpeed, ESuggestProjVelocityTraceOption::DoNotTrace);

	if (AimResult)
	{
		auto AimDir = OLauchVel.GetSafeNormal();
		MoveBarrelTowards(AimDir);
		UE_LOG(LogTemp, Warning, TEXT("Aiming at %s"), *AimDir.ToString());
	}


	// Calculate out launch




	//auto tName = GetOwner()->GetName();
	//auto barrelLocation = TankBarrel->GetComponentLocation();

}


void UTankAimingComponent::SetBarrel(UTankBarrel* barrelSet)
{
	TankBarrel = barrelSet;
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDir)
{
	auto barrelRot = TankBarrel->GetForwardVector().Rotation();

	auto AimAsRotator = AimDir.Rotation();

	auto deltaRot = AimAsRotator - barrelRot;


	TankBarrel->Elevate(5);

}
