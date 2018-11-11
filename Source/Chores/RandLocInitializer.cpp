// Fill out your copyright notice in the Description page of Project Settings.

#include "RandLocInitializer.h"


// Sets default values for this component's properties
URandLocInitializer::URandLocInitializer()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void URandLocInitializer::MoveToRandomLocation(TArray<AActor*> possibleLocations)
{
	int index = rand() % possibleLocations.Num();
	GetOwner()->SetActorLocation(possibleLocations[index]->GetActorLocation());
}

TArray<AActor*> URandLocInitializer::GetAllRoadActors()
{
	TArray<AActor*> roadActors;
	for (TActorIterator<AActor> It(GetWorld()); It; ++It) {
		if (It->GetName().Contains("Road")) {
			roadActors.Add(*It);
		}
	}
	return roadActors;
}

// Called when the game starts
void URandLocInitializer::BeginPlay()
{
	Super::BeginPlay();
	srand(time(0));
	// ...
	
}


// Called every frame
void URandLocInitializer::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

