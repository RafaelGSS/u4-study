// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn1.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"

// Sets default values
AMyPawn1::AMyPawn1()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	this->StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	this->StaticMesh->SetSimulatePhysics(true);
	RootComponent = this->StaticMesh;

	this->Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	this->Camera->SetupAttachment(RootComponent);
	this->Camera->AddRelativeLocation(FVector(-330, 0, 130));
}

// Called when the game starts or when spawned
void AMyPawn1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Y", this, &AMyPawn1::MoveVertically);
	PlayerInputComponent->BindAxis("MouseX", this, &AMyPawn1::RotateZAxis);
}

void AMyPawn1::MoveVertically(float yAxis)
{
	FVector CurrentPosition = GetActorLocation();
	FVector Forward = GetActorForwardVector();
	SetActorLocation(CurrentPosition + (Forward * yAxis * this->Speed));
}

void AMyPawn1::RotateZAxis(float xAxis)
{
	FRotator CurrentRotation = GetActorRotation();
	FRotator zAxis = FRotator::MakeFromEuler(FVector(0.f, 0.f, 1.f));
	SetActorRotation(CurrentRotation + (zAxis * xAxis * this->SpeedRotation));
}

