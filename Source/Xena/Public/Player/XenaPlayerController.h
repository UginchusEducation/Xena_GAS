// Copyright Uginchus Education

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/PlayerController.h"
#include "XenaPlayerController.generated.h"

class USplineComponent;
class UXenaAbilitySystemComponent;
class UXenaInputConfig;
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

	void AbilityInputTagPressed(FGameplayTag GameplayTag);
	void AbilityInputTagReleased(FGameplayTag GameplayTag);
	void AbilityInputTagHeld(FGameplayTag GameplayTag);

	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UXenaInputConfig> InputConfig;

	UPROPERTY()
	TObjectPtr<UXenaAbilitySystemComponent> XenaASC;

	UXenaAbilitySystemComponent* GetASC();

	FVector CachedDestination = FVector::ZeroVector;
	float FollowTime = 0.f;
	float ShortPressThreshold = 0.5f;
	bool bAutoRunning = false;
	bool bTargeting = false;

	UPROPERTY(EditDefaultsOnly)
	float AutoRunAcceptanceRadius = 50.f;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USplineComponent> Spline;
};
