// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayTagAssetInterface.h"
#include "PickupActorInterface.h"
#include "PlayerCharacter.generated.h"



class UInputMappingContext;
class UPlayerInputConfigData;
class USpringArmComponent;
class UCameraComponent;

struct FInputActionValue;


UCLASS()
class FROSTHUNT_API APlayerCharacter : public ACharacter, public IGameplayTagAssetInterface, public IPickupActorInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameplayTags")
	FGameplayTagContainer GameplayTags;

	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override 
	{ 
		TagContainer = GameplayTags; 
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

 	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> DefaultInputMapping;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UPlayerInputConfigData> InputActions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> Camera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
	float WalkingSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
	float RunningSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
	float SprintingSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
	float StrafeSpeedMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
	float BackwardMovementSpeedMultiplier;

	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

	virtual void Jump() override;

	void StartRunning();

	void StopRunning();

	void StartSprinting();

	void Crouch();

	void UnCrouch();
	
	virtual void PossessedBy(AController* NewController) override;


};
