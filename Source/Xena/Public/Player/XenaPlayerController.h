// Copyright Uginchus Education

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "XenaPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class IEnemyInterface;
struct FInputActionValue;

UCLASS()
class XENA_API AXenaPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AXenaPlayerController();
	virtual void PlayerTick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> PlayerContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& InputActionValue);

	void CursorTrace();

	IEnemyInterface* LastActor;
	IEnemyInterface* ThisActor;
};
