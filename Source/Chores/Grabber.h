// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHORES_API UGrabber : public UActorComponent
{
	GENERATED_BODY()


private:
	UPhysicsHandleComponent* PhysicsHandle;
	bool GetTraceInFront(FHitResult* outHit);
	FVector GetInteractLocation();

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:

	UPROPERTY(EditAnywhere)
	float TraceRange = 500;

	UPROPERTY(EditAnywhere)
	float InteractDisplacement = 300;


	// Called when the game starts
	virtual void BeginPlay() override;


	virtual void HandleInteract();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void SetupInputComponent();

	
};
