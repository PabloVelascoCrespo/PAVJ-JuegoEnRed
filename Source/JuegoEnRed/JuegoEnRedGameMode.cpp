// Copyright Epic Games, Inc. All Rights Reserved.

#include "JuegoEnRedGameMode.h"
#include "JuegoEnRedCharacter.h"
#include "UObject/ConstructorHelpers.h"

AJuegoEnRedGameMode::AJuegoEnRedGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
