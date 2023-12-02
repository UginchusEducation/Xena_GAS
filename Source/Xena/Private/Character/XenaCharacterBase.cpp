// Copyright Uginchus Education


#include "Character/XenaCharacterBase.h"

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
