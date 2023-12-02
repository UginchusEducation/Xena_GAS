// Copyright Uginchus Education


#include "Character/XenaEnemyCharacter.h"
#include "GAS/XenaAbilitySystemComponent.h"
#include "GAS/XenaAttributeSet.h"
#include "Xena/Xena.h"

AXenaEnemyCharacter::AXenaEnemyCharacter()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UXenaAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UXenaAttributeSet>("AttributeSet");
}

void AXenaEnemyCharacter::HighlightActor()
{
	//UE_LOG(LogEnemyCharacter, Display, TEXT("Highlight Enemy == %s"), *GetName());

	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AXenaEnemyCharacter::UnhighlightActor()
{
	//UE_LOG(LogEnemyCharacter, Display, TEXT("Unhighlight Enemy == %s"), *GetName());

	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

void AXenaEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	InitAbilityActorInfo();
}

void AXenaEnemyCharacter::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<UXenaAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();

}
