// Copyright Uginchus Education

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "XenaGASLibrary.generated.h"

class UOverlayWidgetController;
class UAttributeMenuWidgetController;

UCLASS()
class XENA_API UXenaGASLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure, Category = "XenaGASLibrary|WidgetCOntroller")
	static UOverlayWidgetController* GetOverlayWidgetController(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category = "XenaGASLibrary|WidgetCOntroller")
	static UAttributeMenuWidgetController* GetAttributeMenuWidgetController(const UObject* WorldContextObject);
};
