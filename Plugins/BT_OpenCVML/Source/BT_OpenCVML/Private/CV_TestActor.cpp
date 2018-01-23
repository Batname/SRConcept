// Fill out your copyright notice in the Description page of Project Settings.

#include "CV_TestActor.h"
#include "BT_OpenCVML.h"

// Sets default values
ACV_TestActor::ACV_TestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACV_TestActor::BeginPlay()
{
	Super::BeginPlay();

	auto BT_OpenCVMLModule = FBT_OpenCVMLModule::Get();	
}

// Called every frame
void ACV_TestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

