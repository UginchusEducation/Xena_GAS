// Copyright Uginchus Education

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "XenaCharacterBase.generated.h"

UCLASS(Abstract)
class XENA_API AXenaCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AXenaCharacterBase();

protected:
	virtual void BeginPlay() override;

};
