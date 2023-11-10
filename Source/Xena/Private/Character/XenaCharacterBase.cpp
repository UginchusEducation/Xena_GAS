// Copyright Uginchus Education


#include "Character/XenaCharacterBase.h"

// Sets default values
AXenaCharacterBase::AXenaCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AXenaCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AXenaCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AXenaCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

