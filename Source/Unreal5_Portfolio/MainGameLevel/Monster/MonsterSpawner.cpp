// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameLevel/Monster/MonsterSpawner.h"
#include "Global/MainGameBlueprintFunctionLibrary.h"
#include "Global/DataTable/MonsterDataRow.h"
#include "NavigationSystem.h"

// Sets default values
AMonsterSpawner::AMonsterSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMonsterSpawner::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AMonsterSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SpawnMonster();
}

void AMonsterSpawner::InitSpawner(EMonsterSpawnerType _Type, const FVector& _Location, float _Radius, int _MinSize, int _MaxSize)
{
	SettingData = NewObject<UMonsterSpawnerData>(this);
	SettingData->Location = _Location;
	SettingData->MinSize = _MinSize;
	SettingData->MaxSize = _MaxSize;
	SettingData->Radius = _Radius;
	SettingData->Type = _Type;
}

void AMonsterSpawner::SpawnMonster_Implementation()
{
	UMainGameInstance* MainGameInst = GetWorld()->GetGameInstanceChecked<UMainGameInstance>();
	const FMonsterDataRow* MonsterData = MainGameInst->GetMonsterData(TEXT("MonsterType_1"));

	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	int Size = FMath::RandRange(SettingData->MinSize, SettingData->MaxSize);
	FVector CurLocation = SettingData->Location;

	for (int i = 0; i < Size; i++)
	{
		FNavLocation Location(FVector::ZeroVector);
	    NavSystem->GetRandomReachablePointInRadius(CurLocation, SettingData->Radius, Location);
		Location.Location.Z += 500.0f;

		FTransform Transform;
		Transform.SetLocation(Location);
		GetWorld()->SpawnActor<AActor>(MonsterData->GetMonsterUClass(), Transform);
	}

	switch (SettingData->Type)
	{
	case EMonsterSpawnerType::Once:
		Destroy();
		break;
	}
}