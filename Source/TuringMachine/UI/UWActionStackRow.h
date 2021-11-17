// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TMManager.h"
#include "Blueprint/UserWidget.h"
#include "UWActionStackRow.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable)
class TURINGMACHINE_API UUWActionStackRow : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	class UUWSymbol* StateLabel;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	class UUWSymbol* CurrentSymbolLabel;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (BindWidget))
	class UUWReaction* ReactionLabel;

	UFUNCTION()
	void InitializeFromData(const FTapeActionStruct& Action);
};
