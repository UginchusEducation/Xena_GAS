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

	// Enemy Interface
	virtual void HighlightActor() override;
	virtual void UnhighlightActor() override;

	// Combat Interface
	virtual int32 GetLevel() override;

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CharacterClassDefaults")
	int32 Level = 1;
};
