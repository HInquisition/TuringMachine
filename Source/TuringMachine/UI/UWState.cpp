// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/UWState.h"

#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Components/EditableText.h"

void UUWState::InitializeFromData()
{
	if (LinkedStateStruct)
	{
		PreviousStateName = LinkedStateStruct->Name;
		StateLabel->SetText(FText::FromString(LinkedStateStruct->Name));
		for (int i = 0; i < LinkedStateStruct->Reactions.Num(); ++i)
		{
			UUWEditableReaction* CreatedReaction = CreateWidget<UUWEditableReaction>(this, ReactionWidgetClass);
			Reactions.Add(CreatedReaction);
			CreatedReaction->LinkedReactionStruct = &(LinkedStateStruct->Reactions[i]);
			CreatedReaction->InitializeFromData();
			MainPanel->AddChild(CreatedReaction);
		}

	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("INIT ERROR IN UWSTATE"));
	}
}

void UUWState::UpdateLinkedStateName(const FText Name)
{
	if(LinkedStateStruct)
	{
		LinkedStateStruct->Name = Name.ToString();
	}
}

void UUWState::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	
}
