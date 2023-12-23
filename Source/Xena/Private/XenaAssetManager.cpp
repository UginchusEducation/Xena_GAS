// Copyright Uginchus Education


#include "XenaAssetManager.h"
#include "XenaGameplayTags.h"

UXenaAssetManager& UXenaAssetManager::Get()
{
	check(GEngine);

	UXenaAssetManager* XenaAssetManager = Cast<UXenaAssetManager>(GEngine->AssetManager);
	return *XenaAssetManager;
}

void UXenaAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FXenaGameplayTags::InitializeNativeGameplayTags();
}
