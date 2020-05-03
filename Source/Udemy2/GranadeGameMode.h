// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GranadeGameMode.generated.h"

/**
 * 
 */
UCLASS()
class UDEMY2_API AGranadeGameMode : public AGameModeBase
{
	AGranadeGameMode();
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void StartPlay() override;
};
