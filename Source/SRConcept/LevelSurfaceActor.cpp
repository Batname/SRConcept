// Fill out your copyright notice in the Description page of Project Settings.

#include "LevelSurfaceActor.h"

#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Components/BoxComponent.h"

// Sets default values
ALevelSurfaceActor::ALevelSurfaceActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set root component
	SurfaceComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SurfaceComponent"));
	RootComponent = SurfaceComponent;

	// Setup box collision
	CollisionBox = CreateDefaultSubobject<UBoxComponent>("CollisionBox");
	CollisionBox->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ALevelSurfaceActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALevelSurfaceActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

