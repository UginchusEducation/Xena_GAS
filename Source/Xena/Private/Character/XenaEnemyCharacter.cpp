// Copyright Uginchus Education


#include "Character/XenaEnemyCharacter.h"
#include "Xena/Xena.h"

void AXenaEnemyCharacter::HighlightActor()
{
	//UE_LOG(LogEnemyCharacter, Display, TEXT("Highlight Enemy == %s"), *GetName());

	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AXenaEnemyCharacter::UnhighlightActor()
{
	//UE_LOG(LogEnemyCharacter, Display, TEXT("Unhighlight Enemy == %s"), *GetName());

	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}