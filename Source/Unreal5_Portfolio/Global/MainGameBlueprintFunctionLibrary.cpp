// Fill out your copyright notice in the Description page of Project Settings.


#include "Global/MainGameBlueprintFunctionLibrary.h"
#include "MainGameState.h"

UMainGameInstance* UMainGameBlueprintFunctionLibrary::GetMainGameInstance(const UWorld* WorldContextObject)
{
	UMainGameInstance* MainGameInst = WorldContextObject->GetGameInstanceChecked<UMainGameInstance>();

	if (false == MainGameInst->IsValidLowLevel())
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (false == Inst->IsValidLowLevel())"), __FUNCTION__, __LINE__);
		return nullptr;
	}

	return MainGameInst;
}

AMainGameState* UMainGameBlueprintFunctionLibrary::GetMainGameState(const UObject* WorldContextObject)
{
	if (nullptr == WorldContextObject)
	{
		return nullptr;
	}

	const UWorld* World = Cast<UWorld>(WorldContextObject);
	AMainGameState* GameState = World->GetGameState<AMainGameState>();
	return GameState;
}

void UMainGameBlueprintFunctionLibrary::PushActor(const UObject* WorldContextObject, uint8 _GroupIndex, AActor* _Actor)
{
	if (nullptr == WorldContextObject)
	{
		return;
	}

	const UWorld* World = Cast<UWorld>(WorldContextObject);

	AMainGameState* GameState = World->GetGameState<AMainGameState>();
	if (nullptr == GameState)
	{
		UE_LOG(LogTemp, Fatal, TEXT("%S(%u)> if (nullptr == State)"), __FUNCTION__, __LINE__);
	}

	GameState->PushActor(_GroupIndex, _Actor);
}
