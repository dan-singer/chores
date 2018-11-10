// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraActor.h"
#include "CharacterBase.generated.h"



class ACharacterBase;

USTRUCT(BlueprintType)
struct FMinigame
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ACharacterBase* character;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString instructions;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<ACameraActor*> Cameras;
};


UCLASS()
class CHORES_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void MinigameReady(FMinigame gameData);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
