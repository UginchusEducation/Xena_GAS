// Copyright Uginchus Education

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "XenaAbilitySystemComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FEffectAssetTags, const FGameplayTagContainer& /* AssetTags */);

UCLASS()
class XENA_API UXenaAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:

	void AbilityActorInfoSet();

	FEffectAssetTags EffectAssetTags;

	void AddCharacterAbilities (const TArray<TSubclassOf<UGameplayAbility>> & StartupAbilities);

	void AbilityInputTagHeld(const FGameplayTag& GameplayTag);
	void AbilityInputTagReleased(const FGameplayTag& GameplayTag);

protected:

	void EffectApplied(UAbilitySystemComponent* ASC, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle);

};
