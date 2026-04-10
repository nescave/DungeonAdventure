// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/DAPlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "Globals/ProjectNames.h"


ADAPlayerCharacter::ADAPlayerCharacter()
{
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

	FPCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	FPCamera->SetupAttachment(FPMesh);
}

void ADAPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ADAPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADAPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

