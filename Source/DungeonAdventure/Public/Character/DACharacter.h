// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DACharacter.generated.h"

class UAbilitySystemComponent;
class UBaseCharacterAttributes;
class UGameplayEffect;
class UCameraComponent;


UCLASS()
class DUNGEONADVENTURE_API ADACharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(Category=DACharacter, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> FPMesh;
	
	
protected:
	// Gameplay Abilities System
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Attributes")
	TObjectPtr<UBaseCharacterAttributes> BaseAttributeSet;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AbilitiesSystem")
	TArray<TSubclassOf<UGameplayEffect>> StartupGameplayEffects;
	
public:
	ADACharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// --- First-person camera and bobbing ---
	/** First-person camera component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> FirstPersonCameraComponent;

	/** Enable/disable camera bobbing */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera|Bobbing")
	bool bEnableCameraBobbing = true;

	/** Frequency multiplier for the bobbing (higher = faster oscillation) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera|Bobbing", meta=(ClampMin="0.0"))
	float BobFrequency = 10.0f;

	/** Maximum vertical bob amplitude in cm */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera|Bobbing", meta=(ClampMin="0.0"))
	float MaxBobVertical = 6.0f;

	/** Maximum lateral (side-to-side) bob amplitude in cm */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera|Bobbing", meta=(ClampMin="0.0"))
	float MaxBobLateral = 3.0f;

	/** How quickly the camera returns to rest when movement stops (interp speed) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera|Bobbing", meta=(ClampMin="0.0"))
	float ReturnInterpSpeed = 8.0f;

	/** Phase multiplier applied to lateral bob to shift its timing relative to vertical bob */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera|Bobbing")
	float LateralPhaseMultiplier = 1.0f;

	/** Minimum speed (cm/s) under which bobbing is considered stopped to avoid micro-jitter */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera|Bobbing", meta=(ClampMin="0.0"))
	float BobStopSpeedThreshold = 5.0f;

private:
	// Runtime bobbing state (not exposed)
	float BobPhase = 0.0f;
	FVector CurrentBobOffset = FVector::ZeroVector;
	FVector TargetBobOffset = FVector::ZeroVector;
	FVector BaseCameraRelativeLocation = FVector::ZeroVector;
};
