// Copyright Uginchus Education

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "XenaAssetManager.generated.h"

UCLASS()
class XENA_API UXenaAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:

	static UXenaAssetManager& Get();

protected:
	virtual void StartInitialLoading() override;
};
