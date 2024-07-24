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
	DestroyCheck();
}

void AMonsterSpawner::InitSpawner(EMonsterSpawnerType Type, const FVector& Location, float Radius, int MinSize, int MaxSize)
{
	SettingData = NewObject<UMonsterSpawnerData>(this);
	SettingData->Location = Location;
	SettingData->MinSize = MinSize;
	SettingData->MaxSize = MaxSize;
	SettingData->Radius = Radius;
	SettingData->Type = Type;
}

void AMonsterSpawner::DestroyCheck()
{
	switch (SettingData->Type)
	{
	case EMonsterSpawnerType::Once:
		Destroy();
		break;
	}
}

void AMonsterSpawner::SpawnMonster_Implementation()
{
	UMainGameInstance* MainGameInst = GetWorld()->GetGameInstanceChecked<UMainGameInstance>();

	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(GetWorld());
	int Size = FMath::RandRange(SettingData->MinSize, SettingData->MaxSize);
	FVector CurLocation = SettingData->Location;

	for (int i = 0; i < Size; i++)
	{
		int Type = FMath::RandRange(1, 2);
		FString MonsterType = "BasicZombie_" + FString::FromInt(Type);
		const FMonsterDataRow* MonsterData = MainGameInst->GetMonsterData(FName(MonsterType));

		FNavLocation Location(FVector::ZeroVector);
	    NavSystem->GetRandomReachablePointInRadius(CurLocation, SettingData->Radius, Location);
		
		// 생성 실패 줄이기 위해 높이 수정
		Location.Location.Z += 500.0f;

		FTransform Transform;
		Transform.SetLocation(Location);
		GetWorld()->SpawnActor<AActor>(MonsterData->GetMonsterUClass(), Transform);		
	}
}