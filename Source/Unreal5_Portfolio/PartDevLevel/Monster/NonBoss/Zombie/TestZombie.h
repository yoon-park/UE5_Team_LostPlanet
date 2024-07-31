// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PartDevLevel/Monster/Base/TestMonsterBase.h"
#include "PartDevLevel/Monster/Data/TestZombieData.h"
#include "TestZombie.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL5_PORTFOLIO_API ATestZombie : public ATestMonsterBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	UTestZombieData* ZombieSettingData = nullptr;

};
