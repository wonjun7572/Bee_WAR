// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Bee_WarGameMode.h"
#include "Bee_WarCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABee_WarGameMode::ABee_WarGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
