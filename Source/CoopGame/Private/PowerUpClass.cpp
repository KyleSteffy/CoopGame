// Fill out your copyright notice in the Description page of Project Settings.

#include "PowerUpClass.h"
#include "UnrealNetwork.h"


// Sets default values
APowerUpClass::APowerUpClass()
{
	PowerUpInterval = 0.0f;
	TotalNumberOfTicks = 0.0f;

	bIsPowerUpActive = false;

	SetReplicates(true);

}

void APowerUpClass::OnTickPowerUp()
{
	TicksProcessed++;

	OnPowerUpTicked();



	if (TicksProcessed >= TotalNumberOfTicks)
	{
		OnExpired();

		bIsPowerUpActive = true;
		OnRep_PowerUpActive();

		//Delete Timer
		GetWorldTimerManager().ClearTimer(TimerHandle_PowerUpTick);
	}
}

void APowerUpClass::OnRep_PowerUpActive()
{
	OnPowerUpStateChanged(bIsPowerUpActive);
}


void APowerUpClass::ActivatePowerUp(AActor* ActivateFor)
{
	OnActicvated(ActivateFor);

	bIsPowerUpActive = true;
	OnRep_PowerUpActive();


	if (PowerUpInterval > 0.0f)
	{
		GetWorldTimerManager().SetTimer(TimerHandle_PowerUpTick, this, &APowerUpClass::OnTickPowerUp, PowerUpInterval, true);
	}
	else
	{
		OnTickPowerUp();
	}
}


void APowerUpClass::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APowerUpClass, bIsPowerUpActive);
	
}

