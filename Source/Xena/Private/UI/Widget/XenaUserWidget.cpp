// Copyright Uginchus Education


#include "UI/Widget/XenaUserWidget.h"

void UXenaUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
