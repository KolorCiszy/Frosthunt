// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FrosthuntGameModeBase.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameObjectiveCompleteSignature, class APlayerState*, WhoCompletedGame);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameStartedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameEndedSignature);
/**
 * 
 */
UCLASS()
class FROSTHUNT_API AFrosthuntGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	/* How many items the player should pickup to unlock exit door*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 PickupItemsObjective;

	UFUNCTION(BlueprintCallable)
	void OnGameObjectiveComplete(APlayerState* PlayerCompleting);

	UFUNCTION(BlueprintCallable)
	void OnGameStarted();

	UFUNCTION(BlueprintCallable)
	void OnGameEnded();

	
	UPROPERTY(BlueprintAssignable)
	FOnGameObjectiveCompleteSignature GameObjCompDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnGameEndedSignature GameEndedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnGameStartedSignature GameStartedDelegate;

};
