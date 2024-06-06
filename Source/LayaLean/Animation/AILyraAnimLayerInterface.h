// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AILyraAnimLayerInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UAILyraAnimLayerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class LAYALEAN_API IAILyraAnimLayerInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Animation")
	void IdlePose(FPoseLink& Result);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Animation")
	void StartPose(FPoseLink& Result);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Animation")
	void CyclePost(FPoseLink& Result);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Animation")
	void StopPose(FPoseLink& Result);
};
