// Fill out your copyright notice in the Description page of Project Settings.


#include "DungeonAdventure/Public/Character/DACharacter.h"

#include "AbilitySystemComponent.h"
#include "EnhancedInputComponent.h"
#include "GameplaySystems/GameplayTags.h"
#include "GameplaySystems/Attributes/BaseCharacterAttributes.h"

ADACharacter::ADACharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(false); // <- No Multiplayer :(

	BaseAttributeSet = CreateDefaultSubobject<UBaseCharacterAttributes>(TEXT("BaseCharacterAttributes"));
}

void ADACharacter::BeginPlay()
{
	Super::BeginPlay();

}

void ADACharacter::HandleMove()
{
	AddMovementInput(FVector(MoveVector.X, MoveVector.Y, 0.0f));
}

void ADACharacter::HandleLook()
{
	AddControllerYawInput(LookVector.X);
	AddControllerPitchInput(-LookVector.Y);
}

void ADACharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADACharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ADACharacter::ProcessMoveInput);
		EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &ADACharacter::ProcessLookInput);
	}
}

void ADACharacter::ProcessMoveInput(const FInputActionValue& InputValue)
{
	MoveVector = InputValue.Get<FVector2D>();	 
	if (MoveVector.IsNearlyZero())
	{
		FGameplayTagContainer MoveAbilityTag = FGameplayTagContainer(FDAGameplayTags::Ability::Move);
		AbilitySystemComponent->CancelAbilities(&MoveAbilityTag);
		return;
	}
	
	if (!TryActivateAbilityByTag(FGameplayTagContainer(FDAGameplayTags::Ability::Move)))
	{
		// inform player he can't move
	}
}

void ADACharacter::ProcessLookInput(const FInputActionValue& InputValue)
{
	LookVector = InputValue.Get<FVector2D>();
	if (LookVector.IsNearlyZero())
	{
		FGameplayTagContainer LookAbilityTag = FGameplayTagContainer(FDAGameplayTags::Ability::Look);
		AbilitySystemComponent->CancelAbilities(&LookAbilityTag);
		return;
	}
	if (!TryActivateAbilityByTag(FGameplayTagContainer(FDAGameplayTags::Ability::Look)))
	{
		// probably player is frozen or dead something
	}
}


bool ADACharacter::TryActivateAbilityByTag(FGameplayTagContainer AbilityTags)
{
	return AbilitySystemComponent->TryActivateAbilitiesByTag(AbilityTags);
}
