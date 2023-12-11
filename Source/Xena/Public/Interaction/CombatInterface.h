// Copyright Uginchus Education

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CombatInterface.generated.h"

UINTERFACE(MinimalAPI)
class UCombatInterface : public UInterface
{
	GENERATED_BODY()
};

class XENA_API ICombatInterface
{
	GENERATED_BODY()

public:
	virtual int32 GetLevel();
};
