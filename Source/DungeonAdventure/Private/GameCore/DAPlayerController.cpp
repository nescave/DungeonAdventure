// Fill out your copyright notice in the Description page of Project Settings.


#include "GameCore/DAPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "GameCore/DAGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "Character/DACharacter.h"

ADAPlayerController::ADAPlayerController()
{
}

void ADAPlayerController::BeginPlay()
{
	Super::BeginPlay();
	CurrentGameMode = Cast<ADAGameMode>(UGameplayStatics::GetGameMode(this));
}

void ADAPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (IsLocalPlayerController())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				Subsystem->AddMappingContext(CurrentContext, 0);
			}
		}
	}
}

void ADAPlayerController::ProcessMoveInput(const FVector2D& MoveVector)
{
	GetDACharacter()->HandleMove(MoveVector);
}

ADACharacter* ADAPlayerController::GetDACharacter() const
{
	if (!IsLocalPlayerController())
	{
		return nullptr;		
	}
	if (GetCharacter() != DACharacter)
	{
		DACharacter = Cast<ADACharacter>(GetCharacter());
	}
	return DACharacter;
	
}

