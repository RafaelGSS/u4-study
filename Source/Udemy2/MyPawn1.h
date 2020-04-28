// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn1.generated.h"

UCLASS()
class UDEMY2_API AMyPawn1 : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn1();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
	float SpeedRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
	float Height;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General")
	bool isAlive;

	UPROPERTY(VisibleDefaultsOnly)
	FName name;

	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleDefaultsOnly)
	class UCameraComponent* Camera;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void MoveVertically(float yAxis);

	UFUNCTION()
	void RotateZAxis(float xAxis);
};
