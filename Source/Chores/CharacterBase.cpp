// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterBase.h"
#include "Grabber.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACharacterBase::MinigameReady(FMinigame gameData)
{
	auto* camManager = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
	camManager->ViewYawMin = 0;
	camManager->ViewYawMax = 359.998993f;
}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UGrabber* grabber = FindComponentByClass<UGrabber>();
	if (grabber) {
		grabber->SetupInputComponent();
	}

}

