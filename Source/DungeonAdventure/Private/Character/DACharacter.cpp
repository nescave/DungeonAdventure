// Fill out your copyright notice in the Description page of Project Settings.


#include "DungeonAdventure/Public/Character/DACharacter.h"

#include "AbilitySystemComponent.h"
#include "GameplaySystems/Attributes/BaseCharacterAttributes.h"
#include "Globals/ProjectNames.h"


// Sets default values
ADACharacter::ADACharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	FPMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FPMesh"));
	if (FPMesh)
	{
		FPMesh->bOwnerNoSee = false;
		FPMesh->bCastDynamicShadow = false;
		FPMesh->bAffectDynamicIndirectLighting = false;
		FPMesh->SetupAttachment(RootComponent);
		FPMesh->SetCollisionProfileName(DACollisionProfile::NoCollision);
		FPMesh->SetGenerateOverlapEvents(false);
		FPMesh->SetCanEverAffectNavigation(false);
		FPMesh->SetFirstPersonPrimitiveType(EFirstPersonPrimitiveType::FirstPerson);
	}
	GetMesh()->SetCollisionProfileName(DACollisionProfile::Character);
	GetMesh()->SetOwnerNoSee(true);

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(false); // <- No Multiplayer :(

	BaseAttributeSet = CreateDefaultSubobject<UBaseCharacterAttributes>(TEXT("BaseCharacterAttributes"));
}

void ADACharacter::BeginPlay()
{
	Super::BeginPlay();

}

void ADACharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADACharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

