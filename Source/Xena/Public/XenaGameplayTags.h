// Copyright Uginchus Education

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

struct FXenaGameplayTags
{
public:
	static const FXenaGameplayTags& Get() { return GameplayTags; }
	static void InitializeNativeGameplayTags();

	// Attributes (Primary)
	FGameplayTag Attributes_Primary_Strength;
	FGameplayTag Attributes_Primary_Inteligence;
	FGameplayTag Attributes_Primary_Resilience;
	FGameplayTag Attributes_Primary_Vigor;

	// Attributes (Secondary)
	FGameplayTag Attributes_Secondary_HealthRegeneration;
	FGameplayTag Attributes_Secondary_MaxHealth;
	FGameplayTag Attributes_Secondary_ManaRegeneration;
	FGameplayTag Attributes_Secondary_MaxMana;
	FGameplayTag Attributes_Secondary_Armor;
	FGameplayTag Attributes_Secondary_ArmorPenetration;
	FGameplayTag Attributes_Secondary_BlockChance;
	FGameplayTag Attributes_Secondary_CriticalHitChance;
	FGameplayTag Attributes_Secondary_CriticalHitDamage;
	FGameplayTag Attributes_Secondary_CriticalHitResistance;

private:
	static FXenaGameplayTags GameplayTags;
};