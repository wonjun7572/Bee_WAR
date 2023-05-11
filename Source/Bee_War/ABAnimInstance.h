// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Bee_War.h"
#include "Animation/AnimInstance.h"
#include "ABAnimInstance.generated.h"

DECLARE_MULTICAST_DELEGATE(FonNextAttackCheckDelegate);
DECLARE_MULTICAST_DELEGATE(FonAttackHitCheckDelegate);

/**
 * 
 */
UCLASS()
class BEE_WAR_API UABAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UABAnimInstance();
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	void PlayAttackMontage();
	void JumpToAttackMontageSection(int32 NewSection);

public:
	FonNextAttackCheckDelegate OnNextAttackCheck;
	FonAttackHitCheckDelegate OnAttackHitCheck;

private:
	UFUNCTION()
		void AnimNotify_AttackHitCheck();
	UFUNCTION()
		void AnimNotify_NextAttackCheck();
	FName GetAttackMontageSectionName(int32 Section);
	

public:
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = ture))
		float CurrentPawnSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		bool IsInAir;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attack, Meta = (AllowPrivateAccess = true))
		UAnimMontage* AttackMontage;

};
