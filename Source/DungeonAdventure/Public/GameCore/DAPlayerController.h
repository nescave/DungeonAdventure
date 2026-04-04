// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DAPlayerController.generated.h"

class ADAGameMode;
/**
 * 
 */
UCLASS()
class DUNGEONADVENTURE_API ADAPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<ADAGameMode> CurrentGameMode;

	UPROPERTY(EditAnywhere, Category="Input|Input Mappings")
	TArray<UInputMappingContext*> DefaultMappingContexts;
	
public:
	ADAPlayerController();
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
};
