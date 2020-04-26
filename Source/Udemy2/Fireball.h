// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Fireball.generated.h"

UCLASS()
class UDEMY2_API AFireball : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	AFireball();

private:
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* SphereMesh;

	UPROPERTY(EditAnywhere, Category = "Components")
	class USphereComponent* SphereComponent;

	UPROPERTY(EditAnywhere, Category = "Components")
	UParticleSystemComponent* FireParticle;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
