// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "EscapeTheRoomGameMode.h"
#include "EscapeTheRoomHUD.h"
#include "EscapeTheRoomCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEscapeTheRoomGameMode::AEscapeTheRoomGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AEscapeTheRoomHUD::StaticClass();
}
