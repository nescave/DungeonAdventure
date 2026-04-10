// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplaySystems/Abilities/Tasks/Basic/Move/AbilityTask_Move.h"

#include "Character/DACharacter.h"

UAbilityTask_Move* UAbilityTask_Move::CreateTask(UGameplayAbility* OwningAbility, ADACharacter* Character)
{
	UAbilityTask_Move* Task = NewAbilityTask<UAbilityTask_Move>(OwningAbility);
	Task->SetDACharacter(Character);
	return Task;
	
}

void UAbilityTask_Move::Activate()
{
	Super::Activate();
	if (!Ability || !DACharacter)
	{
		EndTask();
	}
}

void UAbilityTask_Move::TickTask(float DeltaTime)
{
	DACharacter->HandleMove();	
}

void UAbilityTask_Move::SetDACharacter(ADACharacter* Character)
{
	DACharacter = Character;
}
