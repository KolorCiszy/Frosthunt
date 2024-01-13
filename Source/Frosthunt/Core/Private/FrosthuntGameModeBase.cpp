// Fill out your copyright notice in the Description page of Project Settings.


#include "Frosthunt/Core/Public/FrosthuntGameModeBase.h"

void AFrosthuntGameModeBase::OnGameObjectiveComplete(APlayerState* PlayerCompleting)
{
	GameObjCompDelegate.Broadcast(PlayerCompleting);
}
void AFrosthuntGameModeBase::OnGameStarted()
{
	GameStartedDelegate.Broadcast();
}
void AFrosthuntGameModeBase::OnGameEnded()
{
	GameEndedDelegate.Broadcast(); 
}