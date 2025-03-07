// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Misc/Timespan.h"
#include "FrosthuntPlayerState.generated.h"


class APickupActorBase;
/**
 * 
 */
UCLASS()
class FROSTHUNT_API AFrosthuntPlayerState : public APlayerState
{
	GENERATED_BODY()
public:

	AFrosthuntPlayerState();

	UFUNCTION(BlueprintCallable, Category = "Player State")
	void IncrementPickedActors();

	UFUNCTION(BlueprintCallable, Category = "Player State Timer")
	void StartGameTimer();
	UFUNCTION(BlueprintPure, Category = "Player State Timer")
	FTimespan GetElapsedTime() const;

	UFUNCTION(BlueprintCallable, Category = "Player State Timer")
	void StopGameTimer();

	UFUNCTION(BlueprintCallable, Category = "Player State Timer")
	void PauseGameTimer();

	UFUNCTION(BlueprintCallable, Category = "Player State Timer")
	void ResumeGameTimer();

	UFUNCTION(BlueprintCallable, Category = "Player State Timer")
	void AddPenaltyDuration(FTimespan ToAdd);

protected:
	UPROPERTY(BlueprintReadWrite)
	int32 PickedActors;

	UPROPERTY(BlueprintReadOnly)
	FDateTime GameStartTime;
	UPROPERTY(BlueprintReadOnly)
	FDateTime GameEndTime;
	UPROPERTY(BlueprintReadOnly)
	FDateTime GamePauseTime;
	
	UPROPERTY(BlueprintReadOnly)
	FTimespan GamePauseDuration;
	UPROPERTY(BlueprintReadOnly)
	FTimespan PenaltyDuration;

	UPROPERTY(BlueprintReadOnly)
	bool bTimerPaused;

	UPROPERTY(BlueprintReadOnly)
	bool bTimerStopped;
};
