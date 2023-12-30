// Copyright Uginchus Education


#include "Input/XenaInputConfig.h"

const UInputAction* UXenaInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound) const
{
	for (const FXenaInputAction& Action: AbilityInputActions)
	{
		if (Action.InputAction && Action.InputTag == InputTag)
		{
			
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find AbilityInputAction for InputTag [%s] on InputConfig [%s]"), *InputTag.ToString(), *GetNameSafe(this));
	}

	return nullptr;
}
