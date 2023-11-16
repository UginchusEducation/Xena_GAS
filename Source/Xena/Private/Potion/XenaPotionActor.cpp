// Copyright Uginchus Education


#include "Potion/XenaPotionActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "GAS/XenaAttributeSet.h"

AXenaPotionActor::AXenaPotionActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	CollisionSphere = CreateDefaultSubobject<USphereComponent>("CollisionSphere");
	CollisionSphere->SetupAttachment(GetRootComponent());
}

void AXenaPotionActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor);
	if (ASCInterface)
	{
		const UXenaAttributeSet* AttributeSet = Cast<UXenaAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UXenaAttributeSet::StaticClass()));
		UXenaAttributeSet* MutbleAttributeSet = const_cast<UXenaAttributeSet*>(AttributeSet);
		MutbleAttributeSet->SetHealth(AttributeSet->GetHealth() + 25.f);
		Destroy();
	}
}

void AXenaPotionActor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void AXenaPotionActor::BeginPlay()
{
	Super::BeginPlay();

	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &AXenaPotionActor::OnOverlap);
	CollisionSphere->OnComponentEndOverlap.AddDynamic(this, &AXenaPotionActor::OnEndOverlap);
}

