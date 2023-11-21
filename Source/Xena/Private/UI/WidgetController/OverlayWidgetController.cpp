// Copyright Uginchus Education


#include "UI/WidgetController/OverlayWidgetController.h"
#include "GAS/XenaAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	//Super::BroadcastInitialValues();
	const UXenaAttributeSet* XAS = CastChecked<UXenaAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(XAS->GetHealth());
	OnMaxHealthChanged.Broadcast(XAS->GetMaxHealth());
	OnManaChanged.Broadcast(XAS->GetMana());
	OnMaxManaChanged.Broadcast(XAS->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UXenaAttributeSet* XAS = CastChecked<UXenaAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(XAS->GetHealthAttribute()).AddUObject(this, &UOverlayWidgetController::HealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(XAS->GetMaxHealthAttribute()).AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(XAS->GetManaAttribute()).AddUObject(this, &UOverlayWidgetController::ManaChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(XAS->GetMaxManaAttribute()).AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
