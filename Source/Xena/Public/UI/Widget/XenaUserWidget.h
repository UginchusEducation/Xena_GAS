// Copyright Uginchus Education

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "XenaUserWidget.generated.h"

UCLASS()
class XENA_API UXenaUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
