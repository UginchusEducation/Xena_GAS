// Copyright Uginchus Education


#include "Character/XenaPlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/XenaPlayerState.h"
#include "AbilitySystemComponent.h"
#include "GAS/XenaAbilitySystemComponent.h"
#include "Player/XenaPlayerController.h"
#include "UI/HUD/XenaHUD.h"

AXenaPlayerCharacter::AXenaPlayerCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AXenaPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// [SERVER] Init ability actor info
	InitAbilityActorInfo();
}

void AXenaPlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// [CLIENT] Init ability actor info
	InitAbilityActorInfo();
}

void AXenaPlayerCharacter::InitAbilityActorInfo()
{
	AXenaPlayerState* XenaPlayerState = GetPlayerState<AXenaPlayerState>();
	check(XenaPlayerState);
	XenaPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(XenaPlayerState, this);
	Cast<UXenaAbilitySystemComponent>(XenaPlayerState->GetAbilitySystemComponent())->AbilityActorInfoSet();
	AbilitySystemComponent = XenaPlayerState->GetAbilitySystemComponent();
	AttributeSet = XenaPlayerState->GetAttributeSet();

	if (AXenaPlayerController* PC = Cast<AXenaPlayerController>(GetController()))
	{
		if (AXenaHUD* XenaHUD = Cast<AXenaHUD>(PC->GetHUD()))
		{
			XenaHUD->InitOverlay(PC, XenaPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}



}
