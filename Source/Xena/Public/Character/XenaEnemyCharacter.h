// Copyright Uginchus Education

#pragma once

#include "CoreMinimal.h"
#include "Character/XenaCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "XenaEnemyCharacter.generated.h"

DEFINE_LOG_CATEGORY_STATIC(LogEnemyCharacter, All, All);

UCLASS()
class XENA_API AXenaEnemyCharacter : public AXenaCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

public:
	AXenaEnemyCharacter();

	virtual void HighlightActor() override;
	virtual void UnhighlightActor() override;

protected:
	virtual void BeginPlay() override;
};
