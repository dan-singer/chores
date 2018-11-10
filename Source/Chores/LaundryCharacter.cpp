// Fill out your copyright notice in the Description page of Project Settings.

#include "LaundryCharacter.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
void ALaundryCharacter::BeginPlay()
{
	Super::BeginPlay();
	auto* camManager = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
	camManager->ViewYawMin = 0;
	camManager->ViewYawMax = 180;

	PhysicsHandle = FindComponentByClass<UPhysicsHandleComponent>();
	if (!PhysicsHandle) {
		return;
	}

}

void ALaundryCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALaundryCharacter::HandleHorizontal(float value)
{
	AddControllerYawInput(value);
}

void ALaundryCharacter::HandleVertical(float value)
{
	AddControllerPitchInput(value);
}

void ALaundryCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Azimuth", this, &ALaundryCharacter::HandleHorizontal);
	PlayerInputComponent->BindAxis("Altitude", this, &ALaundryCharacter::HandleVertical);

}
