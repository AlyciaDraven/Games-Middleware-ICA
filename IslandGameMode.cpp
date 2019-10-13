// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "IslandGameMode.h"
#include "IslandHUD.h"
#include "Kismet/GameplayStatics.h"
#include "IslandCharacter.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"

AIslandGameMode::AIslandGameMode()
	: Super()
{
	PrimaryActorTick.bCanEverTick = true;

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AIslandHUD::StaticClass();


}

void AIslandGameMode::BeginPlay()
{
	Super::BeginPlay();

	SetCurrentState(EGamePlayState::EPlaying);

	MyCharacter = Cast<AIslandCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

}

void AIslandGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MyCharacter)
	{
		if (FMath::IsNearlyZero(MyCharacter->GetHealth(), 0.001f))
		{
			SetCurrentState(EGamePlayState::EGameOver);
		}
	}

}

EGamePlayState AIslandGameMode::GetCurrentState() const
{
	return CurrentState;
}

void AIslandGameMode::SetCurrentState(EGamePlayState NewState)
{
	CurrentState = NewState;
	HandleNewState(CurrentState);
}

void AIslandGameMode::HandleNewState(EGamePlayState NewState)
{
	switch (NewState)
	{
	case EGamePlayState::EPlaying:
	{
		// do nothing
	}
	break;
	// Unknown/default state
	case EGamePlayState::EGameOver:
	{
		UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
	}
	break;
	// Unknown/default state
	default:
	case EGamePlayState::EUnknown:
	{
		// do nothing
	}
	break;
	}
}