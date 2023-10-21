// Fill out your copyright notice in the Description page of Project Settings.


#include "BallPawn.h"

#include "Camera/CameraComponent.h"

// Sets default values
ABallPawn::ABallPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Initialize the ball mesh and set it as the root component
    BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
    RootComponent = BallMesh;

    BallMesh->SetSimulatePhysics(true); // Enable physics simulation

    // Create the SpringArm component
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength = 500.0f;  // The distance from the ball
    CameraBoom->bUsePawnControlRotation = false; // Do not rotate arm based on controller
    CameraBoom->bEnableCameraLag = true;
    CameraBoom->CameraLagSpeed = 3.0f;

    // Create the Camera component
    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);  // Attach camera to the end of the boom
    FollowCamera->bUsePawnControlRotation = false;  // Do not rotate camera based on controller

    UE_LOG(LogTemp, Log, TEXT("ABallPawn"));
}

// Called when the game starts or when spawned
void ABallPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABallPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABallPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ABallPawn::MoveForward(float Value)
{
    FVector ForceToAdd = FVector(Value * MoveForce, 0, 0);
    BallMesh->AddForce(ForceToAdd * InertiaFactor);
}

void ABallPawn::MoveRight(float Value)
{
    FVector ForceToAdd = FVector(0, Value * MoveForce, 0);
    BallMesh->AddForce(ForceToAdd * InertiaFactor);
}