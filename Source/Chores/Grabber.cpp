// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

#define PRINT(x) UE_LOG(LogTemp, Warning, TEXT(x));

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
}


void UGrabber::SetupInputComponent()
{
	UInputComponent* input = GetOwner()->FindComponentByClass<UInputComponent>();
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (!input || !PhysicsHandle)
		return;
	input->BindAction("Interact", EInputEvent::IE_Pressed, this, &UGrabber::HandleInteract);
}

bool UGrabber::GetTraceInFront(FHitResult* outHit)
{
	FVector start;
	FRotator direction;

	APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (!controller)
		return false;
	controller->GetPlayerViewPoint(start, direction);


	bool hit = GetWorld()->LineTraceSingleByChannel(
		*outHit,
		start,
		start + direction.Vector() * TraceRange,
		ECollisionChannel::ECC_GameTraceChannel1
	);
	return hit;
}

FVector UGrabber::GetInteractLocation()
{
	FVector start;
	FRotator direction;

	APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (!controller)
		return FVector();
	controller->GetPlayerViewPoint(start, direction);

	return start + direction.Vector() * InteractDisplacement;

}


void UGrabber::HandleInteract()
{
	if (!PhysicsHandle)
		return;
	if (PhysicsHandle->GetGrabbedComponent()) {
		PhysicsHandle->ReleaseComponent();
	}
	else {
		FHitResult hit;
		if (GetTraceInFront(&hit)) {
			PhysicsHandle->GrabComponent(hit.GetComponent(), NAME_None, hit.GetActor()->GetActorLocation(), true);
		}
	}
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!PhysicsHandle) {
		//PRINT("");
		return;
	}

	FHitResult hit;
	if (PhysicsHandle->GetGrabbedComponent()) {
		PhysicsHandle->SetTargetLocation(GetInteractLocation());
	}
	// ...
}

