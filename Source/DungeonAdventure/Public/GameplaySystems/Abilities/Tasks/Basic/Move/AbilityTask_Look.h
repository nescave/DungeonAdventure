// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "AbilityTask_Look.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONADVENTURE_API UAbilityTask_Look : public UAbilityTask
{
	GENERATED_BODY()
	
	UPROPERTY()
	TObjectPtr<ADACharacter> DACharacter;
public:
	static UAbilityTask_Look* CreateTask(UGameplayAbility* OwningAbility, ADACharacter* Character);
	
	virtual void Activate() override;
	virtual void TickTask(float DeltaTime) override;
	
	void SetDACharacter(ADACharacter* Character);
};
