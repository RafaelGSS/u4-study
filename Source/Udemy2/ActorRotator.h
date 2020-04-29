// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorRotator.generated.h"

UCLASS()
class UDEMY2_API AActorRotator : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* StaticMesh;

public:	
	// Sets default values for this actor's properties
	AActorRotator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
