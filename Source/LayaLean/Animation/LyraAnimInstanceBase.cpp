// Fill out your copyright notice in the Description page of Project Settings.


#include "LyraAnimInstanceBase.h"

#include "GameFramework/CharacterMovementComponent.h"

ULyraAnimInstanceBase::ULyraAnimInstanceBase(): bHasVelocity(false), bHasAcceleration(false),
                                                DistanceSinceLastUpdate(0),
                                                DisplacementSpeed(0)
{
	bUseMultiThreadedAnimationUpdate = true;
}

void ULyraAnimInstanceBase::NativeThreadSafeUpdateAnimation(const float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	const APawn* Pawn = Cast<APawn>(TryGetPawnOwner());
	if (!Pawn)
	{
		return;
	}

	const FRotator CurrentWorldRotation = Pawn->GetActorRotation();
	const FVector CurrentWorldVelocity = Pawn->GetVelocity();
	const FVector CurrentWorldLocation = Pawn->GetActorLocation();

	const UCharacterMovementComponent* MoveComp = Cast<UCharacterMovementComponent>(Pawn->GetMovementComponent());
	if (!MoveComp)
	{
		return;
	}

	const FVector CurrentWorldAcceleration = MoveComp->GetCurrentAcceleration();

	// 使用收集的数据更新动画实例
	UpdateRotationData(CurrentWorldRotation);
	UpdateVelocityData(CurrentWorldVelocity, CurrentWorldRotation);
	UpdateAccelerationData(CurrentWorldAcceleration, CurrentWorldRotation);
	UpdateLocationData(CurrentWorldLocation, DeltaSeconds);
}


// 更新旋转数据
void ULyraAnimInstanceBase::UpdateRotationData(const FRotator& CurrentWorldRotation)
{
	WorldRotation = CurrentWorldRotation;
}

// 更新速度数据
void ULyraAnimInstanceBase::UpdateVelocityData(const FVector& CurrentWorldVelocity,
                                               const FRotator& CurrentWorldRotation)
{
	WorldVelocity = CurrentWorldVelocity;
	WorldVelocity2D = FVector(WorldVelocity.X, WorldVelocity.Y, 0.f);
	LocalVelocity2D = CurrentWorldRotation.Quaternion().RotateVector(WorldVelocity2D);
	bHasVelocity = !FMath::IsNearlyEqual(LocalVelocity2D.SquaredLength(), 0.f);
}

// 更新加速度数据
void ULyraAnimInstanceBase::UpdateAccelerationData(const FVector& CurrentWorldAcceleration,
                                                   const FRotator& CurrentWorldRotation)
{
	WorldAcceleration = CurrentWorldAcceleration;
	WorldAcceleration2D = FVector(WorldAcceleration.X, WorldAcceleration.Y, 0.f);
	LocalAcceleration2D = CurrentWorldRotation.Quaternion().RotateVector(WorldAcceleration2D);
	bHasAcceleration = !FMath::IsNearlyEqual(LocalAcceleration2D.SquaredLength(), 0.f);
}

// 更新位置数据
void ULyraAnimInstanceBase::UpdateLocationData(const FVector& CurrentWorldLocation, const float DeltaSeconds)
{
	DistanceSinceLastUpdate = FVector::Dist(WorldLocation, CurrentWorldLocation);
	WorldLocation = CurrentWorldLocation;
	DisplacementSpeed = DistanceSinceLastUpdate / DeltaSeconds;
}
