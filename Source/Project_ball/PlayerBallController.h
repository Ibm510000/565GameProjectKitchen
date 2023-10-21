// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerBallController.generated.h"

class ABallPawn;
/**
 * 
 */
UCLASS()
class PROJECT_BALL_API APlayerBallController : public APlayerController
{
	GENERATED_BODY()
public:
    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;

private:
    void MoveForward(float Value);
    void MoveRight(float Value);

    ABallPawn* ControlledBall;
};
