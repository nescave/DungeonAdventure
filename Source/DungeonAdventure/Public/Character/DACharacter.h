// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DACharacter.generated.h"

struct FGameplayTagContainer;
class UInputAction;
struct FInputActionValue;
class UAbilitySystemComponent;
class UBaseCharacterAttributes;
class UGameplayEffect;
class UCameraComponent;

UCLASS()
class DUNGEONADVENTURE_API ADACharacter : public ACharacter
{
	GENERATED_BODY()

	friend class UAbilityTask_Move;
	friend class UAbilityTask_Look;
	
protected:
	// Gameplay Abilities System
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Attributes")
	TObjectPtr<UBaseCharacterAttributes> BaseAttributeSet;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AbilitiesSystem")
	TArray<TSubclassOf<UGameplayEffect>> StartupGameplayEffects;

	UPROPERTY(EditDefaultsOnly, Category="Input|Input Actions")
	TObjectPtr<UInputAction> MoveAction;
	UPROPERTY(EditDefaultsOnly, Category="Input|Input Actions")
	TObjectPtr<UInputAction> LookAction;	
	
public:
	ADACharacter();

protected:
	virtual void BeginPlay() override;

	void HandleMove();
	void HandleLook();
	
public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	void ProcessMoveInput(const FInputActionValue& InputValue);
	void ProcessLookInput(const FInputActionValue& InputValue);
	
	bool TryActivateAbilityByTag(FGameplayTagContainer AbilityTags);
	
private: // cached values
	FVector2D MoveVector;
	FVector2D LookVector;

};
