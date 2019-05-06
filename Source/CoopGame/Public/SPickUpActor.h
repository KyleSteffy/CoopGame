// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SPickUpActor.generated.h"


class USphereComponent;
class UDecalComponent;
class APowerUpClass;


UCLASS()
class COOPGAME_API ASPickUpActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASPickUpActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* SphereComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UDecalComponent* DecalComp;

	UPROPERTY(EditInstanceOnly, Category = "PickUpActor")
	TSubclassOf<APowerUpClass> PowerUpClass;


	APowerUpClass* PowerUpInstance;

	UPROPERTY(EditInstanceOnly, Category = "PickUpActor")
	float CoolDownDuration;

	FTimerHandle TimerHandle_RespawnTimer;

	void Respawn();

public:	

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	
	
};
