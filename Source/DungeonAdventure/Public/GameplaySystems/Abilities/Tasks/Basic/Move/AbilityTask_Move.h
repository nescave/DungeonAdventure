// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "AbilityTask_Move.generated.h"

class UGameplayAbility;
class ADACharacter;
/**
 * 
 */
UCLASS()
class DUNGEONADVENTURE_API UAbilityTask_Move : public UAbilityTask
{
	GENERATED_BODY()
	
	UPROPERTY()
	TObjectPtr<ADACharacter> DACharacter;
	
public:
	static UAbilityTask_Move* CreateTask(UGameplayAbility* OwningAbility, ADACharacter* Character);
	
	virtual void Activate() override;
	virtual void TickTask(float DeltaTime) override;
	
	void SetDACharacter(ADACharacter* Character);
};
