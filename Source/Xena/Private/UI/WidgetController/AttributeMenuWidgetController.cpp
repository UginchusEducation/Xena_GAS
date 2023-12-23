// Copyright Uginchus Education


#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include "GAS/XenaAttributeSet.h"
#include "GAS/XenaAbilitySystemComponent.h"
#include "GAS/Data/AttributeInfo.h"
#include "XenaGameplayTags.h"

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	//Super::BindCallbacksToDependencies();
	
	UXenaAttributeSet* AS = CastChecked<UXenaAttributeSet>(AttributeSet);

	for (auto& Pair : AS->TagToAttributes)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda(
		[this, Pair](const FOnAttributeChangeData& Data)
		{
			BroadcastAttributeInfo(Pair.Key, Pair.Value());
		}
		);
	}
}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	//Super::BindCallbacksToDependencies();

	UXenaAttributeSet* AS = CastChecked<UXenaAttributeSet>(AttributeSet);

	check(AttributeInfo);

	for (auto& Pair : AS->TagToAttributes)
	{
		BroadcastAttributeInfo(Pair.Key, Pair.Value());
	}
}

void UAttributeMenuWidgetController::BroadcastAttributeInfo(const FGameplayTag& AttributeTag, const FGameplayAttribute& Attribute) const
{
	FXenaAttributeInfo Info = AttributeInfo->FindAttributeInfoByTag(AttributeTag);
	Info.AttributeValue = Attribute.GetNumericValue(AttributeSet);
	AttributeInfoDelegate.Broadcast(Info);
}
