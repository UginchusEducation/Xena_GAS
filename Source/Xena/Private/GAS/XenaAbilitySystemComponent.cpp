// Copyright Uginchus Education


#include "GAS/XenaAbilitySystemComponent.h"
#include <XenaGameplayTags.h>

#include "GAS/Abilities/XenaGameplayAbility.h"

void UXenaAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UXenaAbilitySystemComponent::EffectApplied);

	const FXenaGameplayTags& GameplayTags = FXenaGameplayTags::Get();

}

void UXenaAbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities)
{
	for (const TSubclassOf<UGameplayAbility> AbilityClass : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
		if (const UXenaGameplayAbility* XenaAbility = Cast<UXenaGameplayAbility>(AbilitySpec.Ability))
		{
			AbilitySpec.DynamicAbilityTags.AddTag(XenaAbility->StartupInputTag);
			GiveAbility(AbilitySpec);
		}
	}
}

void UXenaAbilitySystemComponent::AbilityInputTagHeld(const FGameplayTag& GameplayTag)
{
	if (!GameplayTag.IsValid()) return;

	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (AbilitySpec.DynamicAbilityTags.HasTagExact(GameplayTag))
		{
			AbilitySpecInputPressed(AbilitySpec);
			if (!AbilitySpec.IsActive())
			{
				TryActivateAbility(AbilitySpec.Handle);
			}
		}
	}
}

void UXenaAbilitySystemComponent::AbilityInputTagReleased(const FGameplayTag& GameplayTag)
{
	if (!GameplayTag.IsValid()) return;

	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (AbilitySpec.DynamicAbilityTags.HasTagExact(GameplayTag))
		{
			AbilitySpecInputReleased(AbilitySpec);
		}
	}
}

void UXenaAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* ASC, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	EffectAssetTags.Broadcast(TagContainer);
}
