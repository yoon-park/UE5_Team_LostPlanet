// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BossKrakenProjectile.generated.h"

class UParticleSystem;
class USphereComponent;
class UStaticMeshComponent;
class UProjectileMovementComponent;

namespace BossKraKenProjectile
{
	enum class EState
	{
		Fly,
		Stop,
		Max
	};
}

UCLASS()
class UNREAL5_PORTFOLIO_API ABossKrakenProjectile : public AActor
{
	GENERATED_BODY()

public:
	ABossKrakenProjectile();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTimes) override;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	void StateUpdate(float DeltaTimes);
	void StateChange(BossKraKenProjectile::EState NextState);

	void Fly(float DeltaTimes);
	void FlyStart();

private:
	// Data
	UPROPERTY(Replicated, EditAnywhere, Category = "SettingData", meta = (AllowPrivateAccess = true))
	float Hp = 100.0f;
	
	UPROPERTY(EditAnywhere, Category = "SettingData", meta = (AllowPrivateAccess = true))
	float Damage = 0.0f;

	UPROPERTY(EditAnywhere, Category = "SettingData", meta = (AllowPrivateAccess = true))
	float RotateSpeed = 0.0f;

	BossKraKenProjectile::EState CurState = BossKraKenProjectile::EState::Max;

private:
	// Component
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = true))
	USphereComponent* BodyCollision = nullptr;
	
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* BodyMesh = nullptr;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = true))
	UProjectileMovementComponent* MovementComp = nullptr;

	UPROPERTY(EditAnywhere, Category = "Particle", meta = (AllowPrivateAccess = true))
	UParticleSystem* FireParticle = nullptr;

	UPROPERTY(EditAnywhere, Category = "Particle", meta = (AllowPrivateAccess = true))
	UParticleSystem* CrashParticle = nullptr;

};
