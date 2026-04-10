// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DAPlayerController.generated.h"

class ADACharacter;
class UInputMappingContext;
class UInputAction;
class ADAGameMode;
/**
 * 
 */
UCLASS()
class DUNGEONADVENTURE_API ADAPlayerController : public APlayerController
{
	GENERATED_BODY()

	UPROPERTY(Transient)
	TObjectPtr<ADACharacter> DACharacter;
	
protected:
	UPROPERTY(Transient)
	TObjectPtr<ADAGameMode> CurrentGameMode;

	UPROPERTY(EditDefaultsOnly, Category="Input|Input Mappings")
	TArray<UInputMappingContext*> DefaultMappingContexts;

public:
	ADAPlayerController();
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

public:
	ADACharacter* GetDACharacter() const;
};
