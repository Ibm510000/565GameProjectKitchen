// Fill out your copyright notice in the Description page of Project Settings.


#include "RaceGameModeBase.h"

#include "PlayerBallController.h"

ARaceGameModeBase::ARaceGameModeBase() {
	PlayerControllerClass = APlayerBallController::StaticClass();
}
