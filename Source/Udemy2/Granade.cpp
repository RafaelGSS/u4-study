// Fill out your copyright notice in the Description page of Project Settings.


#include "Granade.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Engine/EngineTypes.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/AudioComponent.h"
#include "TimerManager.h"
#include "Sound/SoundCue.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGranade::AGranade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	this->GranadeComponent = CreateDefaultSubobject<USphereComponent>(FName("GranadeCp"));
	this->GranadeComponent->SetSphereRadius(12.f);
	this->GranadeComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	RootComponent = this->GranadeComponent;

	this->GranadeMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("GranadeMs"));
	this->GranadeMesh->SetRelativeLocation(FVector(3.2f, 0.f, 0.f));
	this->GranadeMesh->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
	this->GranadeMesh->SetupAttachment(RootComponent);

	this->ExplodeSound = CreateDefaultSubobject<UAudioComponent>(FName("Exploded sound"));
	this->ExplodeSound->bAutoActivate = false;
	this->ExplodeSound->bAutoDestroy = true;
	this->ExplodeSound->SetupAttachment(this->GranadeMesh);

	this->ExplodeParticle = CreateDefaultSubobject<UParticleSystemComponent>(FName("Exploded Particle"));
	this->ExplodeParticle->bAutoActivate = false;
	this->ExplodeParticle->bAutoDestroy = true;
	this->ExplodeParticle->SetupAttachment(this->GranadeMesh);
	
	ConstructorHelpers::FObjectFinder<USoundCue> GranadeSound(TEXT("SoundCue'/Game/StarterContent/Audio/Explosion_Cue.Explosion_Cue'"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> Granade(TEXT("StaticMesh'/Game/FBX/granada.granada'"));
	ConstructorHelpers::FObjectFinder<UParticleSystem> GranadeExplosion(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));

	if (Granade.Succeeded() && GranadeSound.Succeeded() && GranadeExplosion.Succeeded()) {
		this->GranadeMesh->SetStaticMesh(Granade.Object);
		this->ExplodeSound->SetSound(GranadeSound.Object);
		this->ExplodeParticle->SetTemplate(GranadeExplosion.Object);
	}
}

// Called when the game starts or when spawned
void AGranade::BeginPlay()
{
	Super::BeginPlay();
	this->SlowTime(0.1f);
	this->GranadeMesh->SetSimulatePhysics(true);
	this->GranadeMesh->SetEnableGravity(true);
	GetWorldTimerManager().SetTimer(this->Timer, this, &AGranade::ExplodeGranade, 5.f, false);
}

void AGranade::SlowTime(float delay)
{
	UGameplayStatics::SetGlobalTimeDilation(GetWorld(), delay);
	GetWorldTimerManager().SetTimer(this->TimeTimer, this, &AGranade::RestoreTime, 3.f * delay);
}

void AGranade::RestoreTime()
{
	UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 1.f);
	GetWorldTimerManager().ClearTimer(this->TimeTimer);
}

void AGranade::ExplodeGranade()
{
	SetLifeSpan(5.5f);
	this->ExplodeSound->Play();
	this->SlowTime(0.05);
	this->ExplodeParticle->ActivateSystem();
	this->GranadeMesh->SetVisibility(false);
}

// Called every frame
void AGranade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGranade::EndPlay(const EEndPlayReason::Type EndplayReason)
{
	Super::EndPlay(EndplayReason);
	GetWorldTimerManager().ClearTimer(Timer);
}

