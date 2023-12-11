// Copyright Uginchus Education


#include "Player/XenaPlayerState.h"
#include "GAS/XenaAbilitySystemComponent.h"
#include "GAS/XenaAttributeSet.h"
#include <Net/UnrealNetwork.h>

AXenaPlayerState::AXenaPlayerState()
{
	NetUpdateFrequency = 100.f;

	AbilitySystemComponent = CreateDefaultSubobject<UXenaAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UXenaAttributeSet>("AttributeSet");
}

void AXenaPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AXenaPlayerState, Level);
}

UAbilitySystemComponent* AXenaPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AXenaPlayerState::OnRep_Level(int32 OldLevel)
{
}
