// Fill out your copyright notice in the Description page of Project Settings.


#include "Fireball.h"

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AFireball::AFireball()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("root"));
	this->SphereComponent->InitSphereRadius(100.f);
	this->SphereComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	RootComponent = this->SphereComponent;

	this->SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	this->FireParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Fire Particle"));

	this->FireParticle->SetupAttachment(this->SphereMesh);
	this->FireParticle->bAutoActivate = true;

	ConstructorHelpers::FObjectFinder<UStaticMesh> Sphere(
		TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'")
	);

	ConstructorHelpers::FObjectFinder<UMaterialInterface> Material(
		TEXT("Material'/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold'")
	);

	ConstructorHelpers::FObjectFinder<UParticleSystem> Fire(
		TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'")
	);

	if (Sphere.Succeeded() && Material.Succeeded() && Fire.Succeeded()) {
		this->SphereMesh->SetStaticMesh(Sphere.Object);
		this->SphereMesh->SetMaterial(0, Material.Object);
		this->SphereMesh->SetRelativeLocation(FVector(0.f, 0.f, -60.f));

		this->FireParticle->SetTemplate(Fire.Object);
	}

	this->SphereMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AFireball::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFireball::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

