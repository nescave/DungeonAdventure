// Fill out your copyright notice in the Description page of Project Settings.

#include "GameplaySystems/Abilities/Basic/Move/MoveAbility.h"

#include "Abilities/Tasks/AbilityTask.h"
#include "Character/DACharacter.h"
#include "GameplaySystems/GameplayTags.h"
#include "GameplaySystems/Abilities/Tasks/Basic/Move/AbilityTask_Move.h"

UMoveAbility::UMoveAbility()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	SetAssetTags(FGameplayTagContainer(FDAGameplayTags::Ability::Move));
}

void UMoveAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                   const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	DACharacter = Cast<ADACharacter>(ActorInfo->OwnerActor);
	
	if (!DACharacter)
	{
		CancelAbility(Handle, ActorInfo, ActivationInfo, false);
		return;
	}
	
	UAbilityTask_Move* MoveTask = UAbilityTask_Move::CreateTask(this, DACharacter);;
	MoveTask->ReadyForActivation();

	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}
