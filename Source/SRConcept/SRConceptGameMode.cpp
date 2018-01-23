// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "SRConceptGameMode.h"
#include "SRConceptPlayerController.h"
#include "SRConceptCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASRConceptGameMode::ASRConceptGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ASRConceptPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	//if (PlayerPawnBPClass.Class != NULL)
	//{
	//	DefaultPawnClass = PlayerPawnBPClass.Class;
	//}
}