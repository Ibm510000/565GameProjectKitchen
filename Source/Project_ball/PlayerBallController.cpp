#include "PlayerBallController.h"
#include "BallPawn.h"

void APlayerBallController::BeginPlay()
{
    Super::BeginPlay();

    ControlledBall = Cast<ABallPawn>(GetPawn());
    if (!ControlledBall)
    {
        UE_LOG(LogTemp, Warning, TEXT("BallPlayerController not possessing a BallController pawn"));
    }
}

void APlayerBallController::SetupInputComponent()
{
    Super::SetupInputComponent();

    // Bind the movement functions
    InputComponent->BindAxis("MoveForward", this, &APlayerBallController::MoveForward);
    InputComponent->BindAxis("MoveRight", this, &APlayerBallController::MoveRight);
}

void APlayerBallController::MoveForward(float Value)
{
    if (ControlledBall)
    {
        ControlledBall->MoveForward(Value);
    }
}

void APlayerBallController::MoveRight(float Value)
{
    if (ControlledBall)
    {
        ControlledBall->MoveRight(Value);
    }
}
