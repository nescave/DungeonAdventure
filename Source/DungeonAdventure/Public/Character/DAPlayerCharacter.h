// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DACharacter.h"
#include "DAPlayerCharacter.generated.h"

UCLASS()
class DUNGEONADVENTURE_API ADAPlayerCharacter : public ADACharacter
{
	GENERATED_BODY()

public:
	ADAPlayerCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
