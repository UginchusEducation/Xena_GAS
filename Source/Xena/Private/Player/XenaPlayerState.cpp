// Copyright Uginchus Education


#include "Player/XenaPlayerState.h"
#include "GAS/XenaAbilitySystemComponent.h"
#include "GAS/XenaAttributeSet.h"

AXenaPlayerState::AXenaPlayerState()
{
	NetUpdateFrequency = 100.f;

	AbilitySystemComponent = CreateDefaultSubobject<UXenaAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UXenaAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AXenaPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
