// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealLecture1GameMode.h"
#include "UnrealLecture1Character.h"
#include "UObject/ConstructorHelpers.h"

AUnrealLecture1GameMode::AUnrealLecture1GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
