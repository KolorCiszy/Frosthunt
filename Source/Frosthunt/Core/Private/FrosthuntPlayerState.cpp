// Fill out your copyright notice in the Description page of Project Settings.


#include "Frosthunt/Core/Public/FrosthuntPlayerState.h"
#include "Frosthunt/Core/Public/FrosthuntGameModeBase.h"
#include "Frosthunt/Core/Public/PickupActorBase.h"

AFrosthuntPlayerState::AFrosthuntPlayerState()
{
	bTimerStopped = true;
	GameStartTime = 0;
	GameEndTime = 0;
	GamePauseTime = 0;
}
void AFrosthuntPlayerState::IncrementPickedActors()
{
	PickedActors++;

	if (auto GameMode = Cast<AFrosthuntGameModeBase>(GetWorld()->GetAuthGameMode()))
	{
		if (PickedActors >= GameMode->PickupItemsObjective)
		{
			GameMode->OnGameObjectiveComplete(this);
		}
	}
}
FTimespan AFrosthuntPlayerState::GetElapsedTime() const
{
	if (!bTimerPaused && !bTimerStopped)
	{
		return FDateTime::Now() - GameStartTime - GamePauseDuration;
	}
	else if (bTimerPaused)
	{
		return GamePauseTime - GameStartTime - GamePauseDuration;
	}
	else // Timer stopped
	{
		return GameEndTime - GameStartTime - GamePauseDuration;
	}
	
}
void AFrosthuntPlayerState::StartGameTimer()
{
	GameStartTime = FDateTime::Now();
	bTimerStopped = false;
}

void AFrosthuntPlayerState::StopGameTimer()
{
	GameEndTime = FDateTime::Now();
	bTimerStopped = true;
}
void AFrosthuntPlayerState::PauseGameTimer()
{
	if (!bTimerPaused && !bTimerStopped)
	{
		GamePauseTime = FDateTime::Now();
		bTimerPaused = true;
	}
}
void AFrosthuntPlayerState::ResumeGameTimer()
{
	if (bTimerPaused && !bTimerStopped)
	{
		GamePauseDuration += FDateTime::Now() - GamePauseTime;
		bTimerPaused = false;
	}
}