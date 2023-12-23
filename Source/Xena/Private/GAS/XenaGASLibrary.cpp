// Copyright Uginchus Education


#include "GAS/XenaGASLibrary.h"
#include <Kismet/GameplayStatics.h>
#include <UI/HUD/XenaHUD.h>
#include <Player/XenaPlayerState.h>
#include <UI/WidgetController/XenaWidgetController.h>

UOverlayWidgetController* UXenaGASLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AXenaHUD* XenaHUD = Cast<AXenaHUD>(PC->GetHUD()))
		{
			AXenaPlayerState* PS = PC->GetPlayerState<AXenaPlayerState>();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
			return XenaHUD->GetOverlayWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}

UAttributeMenuWidgetController* UXenaGASLibrary::GetAttributeMenuWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AXenaHUD* XenaHUD = Cast<AXenaHUD>(PC->GetHUD()))
		{
			AXenaPlayerState* PS = PC->GetPlayerState<AXenaPlayerState>();
			UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
			UAttributeSet* AS = PS->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
			return XenaHUD->GetAttributeMenuWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}
