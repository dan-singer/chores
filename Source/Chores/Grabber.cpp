// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector start;
	FRotator direction;
	FHitResult hit;
	float length = 1000;

	APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	controller->GetPlayerViewPoint(start, direction);

	GetWorld()->LineTraceSingleByChannel(
		hit,
		start,
		start + direction.Vector() * length,
		ECollisionChannel::ECC_GameTraceChannel1
	);

	//TODO physics handle stuff


	UE_LOG(LogTemp, Warning, TEXT("%s"), *hit.Location.ToString());


	// ...
}

