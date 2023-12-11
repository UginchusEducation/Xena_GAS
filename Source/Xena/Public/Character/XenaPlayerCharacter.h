// Copyright Uginchus Education

#pragma once

#include "CoreMinimal.h"
#include "Character/XenaCharacterBase.h"
#include "XenaPlayerCharacter.generated.h"

UCLASS()
class XENA_API AXenaPlayerCharacter : public AXenaCharacterBase
{
	GENERATED_BODY()

public:
	AXenaPlayerCharacter();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	// Combat Interface
	virtual int32 GetLevel() override;

private:
	virtual void InitAbilityActorInfo() override;
};
