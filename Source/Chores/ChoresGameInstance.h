// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "ChoresGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CHORES_API UChoresGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Wins = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int CurrentSceneIteration = 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TotalSceneIterations = 3;

	UFUNCTION(BlueprintCallable)
	void AddWin(){
		++Wins;
	}
	UFUNCTION(BlueprintCallable)
	void NextScene() {
		++CurrentSceneIteration;
		if (CurrentSceneIteration > TotalSceneIterations) {
			UGameplayStatics::OpenLevel(GetWorld(), "EndScreen");
		}
		else {
			UGameplayStatics::OpenLevel(GetWorld(), "Main");
		}
	}

	
};
