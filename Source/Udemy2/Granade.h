// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Granade.generated.h"

UCLASS()
class UDEMY2_API AGranade : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGranade();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimerHandle Timer, TimeTimer;

	class UAudioComponent* ExplodeSound;

	class UParticleSystemComponent* ExplodeParticle;

	UFUNCTION()
	void SlowTime(float delay);

	UFUNCTION()
	void RestoreTime();

	UFUNCTION()
	void ImpulseRadial(float R, float Force);

	UFUNCTION()
	void ExplodeGranade();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void EndPlay(const EEndPlayReason::Type EndplayReason) override;

private:
	UPROPERTY(EditAnywhere, Category = "Granade")
	class UStaticMeshComponent* GranadeMesh;

	UPROPERTY(EditAnywhere, Category = "Granade")
	class USphereComponent* GranadeComponent;
};
