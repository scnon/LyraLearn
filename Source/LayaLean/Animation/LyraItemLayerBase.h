// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AILyraAnimLayerInterface.h"
#include "Animation/AnimInstance.h"
#include "LyraItemLayerBase.generated.h"

/**
 * 
 */
UCLASS()
class LAYALEAN_API ULyraItemLayerBase : public UAnimInstance, public IAILyraAnimLayerInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	UAnimSequence* IdleAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	UAnimSequence* StartAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	UAnimSequence* CycleAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	UAnimSequence* StopAnimation;
};
