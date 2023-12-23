// Copyright Uginchus Education


#include "GAS/XenaAbilitySystemComponent.h"
#include <XenaGameplayTags.h>

void UXenaAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UXenaAbilitySystemComponent::EffectApplied);

	const FXenaGameplayTags& GameplayTags = FXenaGameplayTags::Get();

}

void UXenaAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* ASC, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	EffectAssetTags.Broadcast(TagContainer);
}
