// Copyright Uginchus Education


#include "GAS/Data/AttributeInfo.h"

FXenaAttributeInfo UAttributeInfo::FindAttributeInfoByTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
	for (const FXenaAttributeInfo& Info : AttributeInformation)
	{
		if (Info.AttributeTag.MatchesTagExact(AttributeTag))
		{
			return Info;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't find info for Attribute === [%s] on AttributeInfo === [%s]"), *AttributeTag.ToString(), *GetNameSafe(this));
	}

	return FXenaAttributeInfo();
}
