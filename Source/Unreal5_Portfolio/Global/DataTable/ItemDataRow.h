// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Global/ContentsEnum.h"
#include "ItemDataRow.generated.h"


USTRUCT(BlueprintType)
struct FItemDataRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	/// <summary>
	/// 아이템 타입 반환
	/// </summary>
	/// <returns></returns>
	EPlayerPosture GetType() const
	{
		return Type;
	}

	/// <summary>
	/// 아이템 이름 반환
	/// </summary>
	/// <returns></returns>
	FString GetName() const
	{
		return Name;
	}

	/// <summary>
	/// 아이템 데미지 반환
	/// </summary>
	/// <returns></returns>
	int GetDamage() const
	{
		return Damage;
	}

	/// <summary>
	/// 장전 단위 반환
	/// </summary>
	/// <returns></returns>
	int GetReloadNum() const
	{
		return ReloadNum;
	}

	/// <summary>
	/// 아이템 StaticMesh 참조형 반환
	/// </summary>
	/// <returns></returns>
	class UStaticMesh* GetResMesh() const
	{
		return ResMesh;
	}

protected:

private:
	/// <summary>
	/// 아이템 종류
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowprivateAccess = "true"))
	EPlayerPosture Type = EPlayerPosture::Number0;

	/// <summary>
	/// 아이템 이름
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowprivateAccess = "true"))
	FString Name = "";

	/// <summary>
	/// 데미지 값
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowprivateAccess = "true"))
	int Damage = 0;

	/// <summary>
	/// 장전 단위
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowprivateAccess = "true"))
	int ReloadNum = -1;

	/// <summary>
	/// 아이템 StaticMesh 리소스 참조 형
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowprivateAccess = "true"))
	class UStaticMesh* ResMesh = nullptr;
};
