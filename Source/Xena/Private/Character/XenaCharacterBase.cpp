// Copyright Uginchus Education


#include "Character/XenaCharacterBase.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"

AXenaCharacterBase::AXenaCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AXenaCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AXenaCharacterBase::BeginPlay()
{
	Super::BeginPlay();

}

void AXenaCharacterBase::InitAbilityActorInfo()
{
}

void AXenaCharacterBase::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> Attribute, float Level) const
{
	const FGameplayEffectContextHandle EffectContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	const FGameplayEffectSpecHandle EffectSpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(Attribute, Level, EffectContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*EffectSpecHandle.Data.Get(), GetAbilitySystemComponent());
}
