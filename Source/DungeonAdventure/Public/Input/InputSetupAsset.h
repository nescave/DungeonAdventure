// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputSetupAsset.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONADVENTURE_API UInputSetupAsset : public UDataAsset
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category ="Input")
	TObjectPtr<UInputAction> MoveAction;
	UPROPERTY(EditAnywhere, Category ="Input")
	TObjectPtr<UInputAction> LookAction;
	UPROPERTY(EditAnywhere, Category ="Input")
	TObjectPtr<UInputAction> JumpAction;
};
