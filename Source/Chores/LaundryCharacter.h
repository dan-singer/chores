// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "LaundryCharacter.generated.h"

/**
 * 
 */
UCLASS()
class CHORES_API ALaundryCharacter : public ACharacterBase
{
	GENERATED_BODY()

private:
	UPhysicsHandleComponent* PhysicsHandle;

	void HandleHorizontal(float value);
	void HandleVertical(float value);

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
