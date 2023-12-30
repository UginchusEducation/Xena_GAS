// Copyright Uginchus Education


#include "Character/XenaCharacterBase.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GAS/XenaAbilitySystemComponent.h"

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
	FGameplayEffectContextHandle EffectContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle EffectSpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(Attribute, Level, EffectContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*EffectSpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void AXenaCharacterBase::InitializeDefaultAttributes() const
{
	// Super::InitializeDefaultAttributes;
}

void AXenaCharacterBase::AddCharacterAbilitues()
{
	UXenaAbilitySystemComponent* XenaASC = CastChecked<UXenaAbilitySystemComponent>(AbilitySystemComponent);
	if(!HasAuthority()) return;

	XenaASC->AddCharacterAbilities(StartupAbilities);
}
