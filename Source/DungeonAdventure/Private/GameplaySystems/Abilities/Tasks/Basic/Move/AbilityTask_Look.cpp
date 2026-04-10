// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplaySystems/Abilities/Tasks/Basic/Move/AbilityTask_Look.h"

#include "Character/DACharacter.h"

UAbilityTask_Look* UAbilityTask_Look::CreateTask(UGameplayAbility* OwningAbility, ADACharacter* Character)
{
	UAbilityTask_Look* Task = NewAbilityTask<UAbilityTask_Look>(OwningAbility);
	Task->SetDACharacter(Character);
	return Task;
}

void UAbilityTask_Look::Activate()
{
	Super::Activate();

	if (!Ability || !DACharacter)
	{
		EndTask();
	}
}

void UAbilityTask_Look::TickTask(float DeltaTime)
{
	DACharacter->HandleLook();
}

void UAbilityTask_Look::SetDACharacter(ADACharacter* Character)
{
	DACharacter = Character;
}
