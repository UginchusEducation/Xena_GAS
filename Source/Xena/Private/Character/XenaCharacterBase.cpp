// Copyright Uginchus Education


#include "Character/XenaCharacterBase.h"

AXenaCharacterBase::AXenaCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AXenaCharacterBase::BeginPlay()
{
	Super::BeginPlay();

}
