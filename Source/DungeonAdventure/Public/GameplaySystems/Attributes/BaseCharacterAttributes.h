// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "BaseCharacterAttributes.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONADVENTURE_API UBaseCharacterAttributes : public UAttributeSet
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseCharacterAttributes, Health)
	UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData MaxHealth;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	FGameplayAttributeData Speed;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseCharacterAttributes, Speed)

	UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData HealthDamage;
	ATTRIBUTE_ACCESSORS_BASIC(UBaseCharacterAttributes, HealthDamage)
	
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
};
