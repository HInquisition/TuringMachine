// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/UWActionStack.h"

#include "UWActionStackRow.h"
#include "Components/ScrollBox.h"

void UUWActionStack::InitializeFromData(const TArray<FTapeActionStruct>& Actions)
{
	for (FTapeActionStruct Action : Actions)
	{

		UUWActionStackRow* CreatedRow = CreateWidget<UUWActionStackRow>(this, ActionRowClass);
		CreatedRow->InitializeFromData(Action);
		MainPanel->AddChild(CreatedRow);
	}

}
