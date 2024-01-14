// Fill out your copyright notice in the Description page of Project Settings.


#include "Frosthunt/Core/Public/PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Frosthunt/Core/Public/PlayerInputConfigData.h"





// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));

	SpringArm->SetupAttachment(GetMesh());

	Camera->AttachToComponent(SpringArm, FAttachmentTransformRules::KeepRelativeTransform);

	SpringArm->bUsePawnControlRotation = true;
	SpringArm->bEnableCameraLag = true;
	SpringArm->TargetArmLength = 300.0f;

	

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void APlayerCharacter::PossessedBy(AController* NewController)
{
	APlayerController* PlayerController = Cast<APlayerController>(NewController);
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
	{
		Subsystem->ClearAllMappings();
		Subsystem->AddMappingContext(DefaultInputMapping, 0);
	}
}
// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(InputActions->InputMove, ETriggerEvent::Triggered, this, &APlayerCharacter::Move);

		EnhancedInputComponent->BindAction(InputActions->InputRun, ETriggerEvent::Started, this, &APlayerCharacter::StartRunning);
		EnhancedInputComponent->BindAction(InputActions->InputRun, ETriggerEvent::Completed, this, &APlayerCharacter::StopRunning);

		EnhancedInputComponent->BindAction(InputActions->InputSprint, ETriggerEvent::Triggered, this, &APlayerCharacter::StartSprinting);
		

		EnhancedInputComponent->BindAction(InputActions->InputJump, ETriggerEvent::Triggered, this, &APlayerCharacter::Jump);

		EnhancedInputComponent->BindAction(InputActions->InputLook, ETriggerEvent::Triggered, this, &APlayerCharacter::Look);

	}
	
}
void APlayerCharacter::Move(const FInputActionValue& Value)
{
	if (Controller == nullptr)
	{
		return;
	}
	FRotator MovementRotation{ 0,0,0 };
	const FVector2D MoveValue = Value.Get<FVector2D>();
	MovementRotation.Yaw = Controller->GetControlRotation().Yaw;

	// Forward/Backward direction
	if (MoveValue.Y != 0.f)
	{
		// Get forward vector
		const FVector Direction = MovementRotation.RotateVector(FVector::ForwardVector);

		AddMovementInput(Direction, MoveValue.Y > 0 ? MoveValue.Y : MoveValue.Y * BackwardMovementSpeedMultiplier);
	}

	// Right/Left direction
	if (MoveValue.X != 0.f)
	{
		// Get right vector
		const FVector Direction = MovementRotation.RotateVector(FVector::RightVector);

		AddMovementInput(Direction, MoveValue.X * StrafeSpeedMultiplier);
	}
}

void APlayerCharacter::Look(const FInputActionValue& Value)
{
	if (Controller != nullptr)
	{
		const FVector2D LookValue = Value.Get<FVector2D>();

		if (LookValue.X != 0.f)
		{
			AddControllerYawInput(LookValue.X);
		}

		if (LookValue.Y != 0.f)
		{
			AddControllerPitchInput(-LookValue.Y);
		}
	}
}

void APlayerCharacter::Jump()
{
	Super::Jump();
}


void APlayerCharacter::StartRunning()
{
	GetCharacterMovement()->MaxWalkSpeed = RunningSpeed;
}
void APlayerCharacter::StopRunning()
{
	GetCharacterMovement()->MaxWalkSpeed = WalkingSpeed;
}
void APlayerCharacter::StartSprinting()
{
	GetCharacterMovement()->MaxWalkSpeed = SprintingSpeed;
}


