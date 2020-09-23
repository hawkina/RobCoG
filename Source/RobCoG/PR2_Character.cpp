// Copyright 2019, Institute for Artificial Intelligence - University of Bremen
// Movement setup following the https://docs.unrealengine.com/en-US/Programming/Tutorials/FirstPersonShooter/2/3/index.html Tutorial

#include "PR2_Character.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
//#include "AnimGraphRuntime/Public/BoneControllers/AnimNode_CCDIK.h"
//#include "CCDIK.h"


// Sets default values
APR2_Character::APR2_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	
}

// Called when the game starts or when spawned
void APR2_Character::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine)
	{
		// Put up a debug message for five seconds. The -1 "Key" value (first argument) indicates that we will never need to update or refresh this message.
		
	}
}

// Called every frame
void APR2_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APR2_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Set up "movement" bindings.
	PlayerInputComponent->BindAxis("MoveForward", this, &APR2_Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APR2_Character::MoveRight);
	PlayerInputComponent->BindAxis("RotateRight", this, &APR2_Character::RotateRight);

	//Action Mapping
	//PlayerInputComponent->BindAction("ResetVr", IE_Pressed, this, &APR2_Character::OnResetVR)

	//AxisMapping
	//PlayerInputComponent->BindAxis("Zoom", this, &APR2_Character::Zoom);

}

void APR2_Character::MoveForward(float Value)
{

	// Find out which way is "forward" and record that the player wants to move that way
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
	
	//FVector	PR2Location = GetActorLocation();
	//PR2Location.X += 10.0f * Value;
	//SetActorLocation(PR2Location, false);


}

void APR2_Character::MoveRight(float Value)
{
	// Find out which way is "right" and record that the player want to move that way.
	//FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	//AddMovementInput(Direction, Value);

}

void APR2_Character::RotateRight(float Value)
{
	//AddControllerYawInput(Value);
}