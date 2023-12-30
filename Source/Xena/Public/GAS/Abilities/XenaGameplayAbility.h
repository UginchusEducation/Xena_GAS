// Copyright Uginchus Education

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "XenaGameplayAbility.generated.h"

UCLASS()
class XENA_API UXenaGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, Category="Input")
	FGameplayTag StartupInputTag;	
};
