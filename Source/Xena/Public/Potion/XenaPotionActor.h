// Copyright Uginchus Education

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "XenaPotionActor.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class XENA_API AXenaPotionActor : public AActor
{
	GENERATED_BODY()

public:
	AXenaPotionActor();

	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> CollisionSphere;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;
};
