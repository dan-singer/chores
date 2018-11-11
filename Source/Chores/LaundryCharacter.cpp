// Fill out your copyright notice in the Description page of Project Settings.

#include "LaundryCharacter.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Components/PrimitiveComponent.h"
void ALaundryCharacter::BeginPlay()
{
	Super::BeginPlay();



}

void ALaundryCharacter::Reset()
{
	Super::Reset();
	auto* camManager = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
	camManager->ViewYawMin = 0;
	camManager->ViewYawMax = 180;

	PhysicsHandle = FindComponentByClass<UPhysicsHandleComponent>();
	if (!PhysicsHandle) {
		return;
	}

	SpawnBall();
}

void ALaundryCharacter::SpawnBall()
{
	CurrentBall = GetWorld()->SpawnActor(BallClass);
	if (!CurrentBall)
		return;
	CurrentBall->SetActorLocation(GetActorLocation() + GetActorForwardVector() * 5);
	UPrimitiveComponent* rootComponent = Cast<UPrimitiveComponent>(CurrentBall->GetRootComponent());
	if (!rootComponent)
		return;
	PhysicsHandle->GrabComponent(rootComponent, NAME_None, CurrentBall->GetActorLocation(), true);
}

void ALaundryCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (CurrentBall) {
		FVector start; FRotator rotation;
		auto* pc = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		pc->GetPlayerViewPoint(start, rotation);

		PhysicsHandle->SetTargetLocation(start + rotation.Vector() * 150);
		UE_LOG(LogTemp, Warning, TEXT("Here"));
	}
}

void ALaundryCharacter::HandleHorizontal(float value)
{
	AddControllerYawInput(value);
}

void ALaundryCharacter::HandleVertical(float value)
{
	AddControllerPitchInput(value);
}

void ALaundryCharacter::HandleFire()
{
	if (CurrentBall) {
		PhysicsHandle->ReleaseComponent();
		UPrimitiveComponent* ballComp = Cast<UPrimitiveComponent>(CurrentBall->GetRootComponent());

		FVector start; FRotator rotation;
		auto* pc = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		pc->GetPlayerViewPoint(start, rotation);

		ballComp->AddImpulse(rotation.Vector() * 500, NAME_None, true);
		
		CurrentBall = nullptr;
	}
}

void ALaundryCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Azimuth", this, &ALaundryCharacter::HandleHorizontal);
	PlayerInputComponent->BindAxis("Altitude", this, &ALaundryCharacter::HandleVertical);
	PlayerInputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &ALaundryCharacter::HandleFire);



}