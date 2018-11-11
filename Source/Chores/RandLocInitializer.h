// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "EngineUtils.h"
#include <stdlib.h>
#include <time.h>
#include "RandLocInitializer.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHORES_API URandLocInitializer : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URandLocInitializer();

	UFUNCTION(BlueprintCallable)
	void MoveToRandomLocation(TArray<AActor*> possibleLocations);

	UFUNCTION(BlueprintCallable)
	TArray<AActor*> GetAllRoadActors();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
