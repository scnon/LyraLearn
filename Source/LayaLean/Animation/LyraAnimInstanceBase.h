// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "LyraAnimInstanceBase.generated.h"

/**
 * 
 */
UCLASS()
class LAYALEAN_API ULyraAnimInstanceBase : public UAnimInstance
{
	GENERATED_BODY()

public:
	ULyraAnimInstanceBase();

protected:
	UFUNCTION(meta=(BlueprintThreadSafe))
	void UpdateRotationData(const FRotator& CurrentWorldRotation);

	UFUNCTION(meta=(BlueprintThreadSafe))
	void UpdateVelocityData(const FVector& CurrentWorldVelocity, const FRotator& CurrentWorldRotation);

	UFUNCTION(meta=(BlueprintThreadSafe))
	void UpdateAccelerationData(const FVector& CurrentWorldAcceleration, const FRotator& CurrentWorldRotation);

	UFUNCTION(meta=(BlueprintThreadSafe))
	void UpdateLocationData(const FVector& CurrentWorldLocation, const float DeltaSeconds);

	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

private:
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = "速度", meta = (AllowPrivateAccess = "true"))
	FVector WorldVelocity;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = "速度", meta = (AllowPrivateAccess = "true"))
	FVector WorldVelocity2D;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = "速度", meta = (AllowPrivateAccess = "true"))
	FVector LocalVelocity2D;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = "速度", meta = (AllowPrivateAccess = "true"))
	bool bHasVelocity;

	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = "旋转", meta = (AllowPrivateAccess = "true"))
	FRotator WorldRotation;

	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = "加速度", meta = (AllowPrivateAccess = "true"))
	FVector WorldAcceleration;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = "加速度", meta = (AllowPrivateAccess = "true"))
	FVector WorldAcceleration2D;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = "加速度", meta = (AllowPrivateAccess = "true"))
	FVector LocalAcceleration2D;
	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = "加速度", meta = (AllowPrivateAccess = "true"))
	bool bHasAcceleration;

	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = "位置", meta = (AllowPrivateAccess = "true"))
	FVector WorldLocation;

	bool bIsFirstUpdate = true;

	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = "即时", meta = (AllowPrivateAccess = "true"))
	float DistanceSinceLastUpdate;

	UPROPERTY(VisibleAnywhere, Transient, BlueprintReadOnly, Category = "即时", meta = (AllowPrivateAccess = "true"))
	float DisplacementSpeed;
};
