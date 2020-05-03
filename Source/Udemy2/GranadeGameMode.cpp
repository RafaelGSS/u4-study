// Fill out your copyright notice in the Description page of Project Settings.


#include "GranadeGameMode.h"
#include "Engine/TargetPoint.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Granade.h"
#include "UObject/ConstructorHelpers.h"

AGranadeGameMode::AGranadeGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(
		TEXT("Blueprint'/Game/ThirdPersonBP/Blueprints/ThirdPersonCharacter.ThirdPersonCharacter_C'")
	);

	if (PlayerPawnBPClass.Class != nullptr) {
		this->DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AGranadeGameMode::BeginPlay()
{
	Super::BeginPlay();
	TArray<AActor*> GranadeLocation;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), GranadeLocation);
	FActorSpawnParameters params = FActorSpawnParameters();

	if (GranadeLocation.Num()) {
		for (auto Location : GranadeLocation) {
			GetWorld()->SpawnActor<AGranade>(
				Location->GetActorLocation(),
				Location->GetActorRotation(),
				params
			);
		}
	}
}

void AGranadeGameMode::StartPlay()
{
	Super::StartPlay();
}
