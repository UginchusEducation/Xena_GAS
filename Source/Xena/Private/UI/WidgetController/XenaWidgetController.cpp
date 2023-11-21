// Copyright Uginchus Education


#include "UI/WidgetController/XenaWidgetController.h"

void UXenaWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void UXenaWidgetController::BroadcastInitialValues()
{
}

void UXenaWidgetController::BindCallbacksToDependencies()
{
}
