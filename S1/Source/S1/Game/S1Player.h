// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Protocol.pb.h"
#include "S1Player.generated.h"

UCLASS()
class S1_API AS1Player : public ACharacter
{
	GENERATED_BODY()

public:
	AS1Player();
	virtual ~AS1Player();

protected:
	virtual void BeginPlay();
	virtual void Tick(float DeltaSeconds) override;

public:
	bool IsMyPlayer();

	Protocol::MoveState GetMoveState() { return PlayerInfo->state(); }
	void SetMoveState(Protocol::MoveState State);

public:
	void SetObjectInfo(const Protocol::ObjectInfo& info);

	void SetPlayerInfo(const Protocol::PosInfo& Info);
	void SetDestInfo(const Protocol::PosInfo& Info);
	Protocol::PosInfo* GetPlayerInfo() { return PlayerInfo; }

public:
	UFUNCTION(BlueprintNativeEvent)
	void AttackAnim();
	virtual void AttackAnim_Implementation();

protected:
	class Protocol::ObjectInfo* ObjectInfo;

	class Protocol::PosInfo* PlayerInfo; // 현재 위치
	class Protocol::PosInfo* DestInfo; // 목적지

	bool TooFar;

public:
	// Get
	Protocol::ObjectInfo* GetObjectInfo() { return ObjectInfo; }


	// Set
	void SetHealth(float NewHealth);
	void SetDamage(float NewDamage);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerInfo")
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerInfo")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerInfo")
	float Damage;
};
