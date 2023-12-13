// Copyright Uginchus Education


#include "GAS/MMC/MMC_MaxMana.h"
#include "GAS/XenaAttributeSet.h"
#include "Interaction/CombatInterface.h"

UMMC_MaxMana::UMMC_MaxMana()
{
	InteligenceDef.AttributeToCapture = UXenaAttributeSet::GetInteligenceAttribute();
	InteligenceDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	InteligenceDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(InteligenceDef);
}

float UMMC_MaxMana::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	float Inteligence = 0.f;
	GetCapturedAttributeMagnitude(InteligenceDef, Spec, EvaluationParameters, Inteligence);
	Inteligence = FMath::Max<float>(Inteligence, 0.f);

	ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	const int32 PlayerLevel = CombatInterface->GetLevel();

	return 200.f + 3.f * Inteligence + 20.f * PlayerLevel;
}
