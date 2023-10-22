// Fill out your copyright notice in the Description page of Project Settings.


#include "BallPawn.h"

#include "Camera/CameraComponent.h"

// Sets default values
ABallPawn::ABallPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
    SphereCollider->SetSimulatePhysics(true);
	RootComponent = SphereCollider;

    // Initialize the ball mesh and set it as the root component
    BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
    BallMesh->SetupAttachment(RootComponent);
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
    BallMesh->AddForce(ForceToAdd);
}

// Called to bind functionality to input
void ABallPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ABallPawn::MoveForward(float Value)
{
    ForceToAdd = FVector(Value * MoveForce, 0, 0);
    ForceToAdd *= InertiaFactor;
}

void ABallPawn::MoveRight(float Value)
{
    ForceToAdd = FVector(0, Value * MoveForce, 0);
    ForceToAdd *= InertiaFactor;
}