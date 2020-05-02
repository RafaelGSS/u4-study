// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorRotator.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AActorRotator::AActorRotator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	ConstructorHelpers::FObjectFinder<UStaticMesh> RockMesh(
		TEXT("StaticMesh'/Game/StarterContent/Props/SM_Rock.SM_Rock'")
	);

	if (RockMesh.Succeeded()) {
		this->StaticMesh->SetStaticMesh(RockMesh.Object);
		this->StaticMesh->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	}
}

// Called when the game starts or when spawned
void AActorRotator::BeginPlay()
{
	Super::BeginPlay();
	FTransform NewTransform = FTransform(
		FRotator(45.f, 45.f, 90.f),
		FVector(30.f, 30.f, 30.f),
		FVector(0.1f, 0.1f, 0.1f)
	);
	AddActorLocalTransform(NewTransform);
}

// Called every frame
void AActorRotator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalRotation(FRotator(0.f, 50.f, 0.f) * DeltaTime);
}

