// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
  PrimaryActorTick.bCanEverTick = true;
  SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::Tick(float DeltaTime)
{
  Super::Tick(DeltaTime);
  //...

  if (ActiveTriggers > 0)
  {
    if (HasAuthority())
    {
      MovementControl(DeltaTime);
    }
  }
}

void AMovingPlatform::AddActiveTrigger()
{ 
  ++ActiveTriggers;
}

void AMovingPlatform::RemoveActiveTrigger()
{
  if (ActiveTriggers > 0)
  {
    --ActiveTriggers;
  }
}

void AMovingPlatform::BeginPlay()
{
  Super::BeginPlay();

  if (HasAuthority())
  {
    SetReplicates(true);
    SetReplicateMovement(true);
  }

  GlobalStartLocation = GetActorLocation();
  GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

void AMovingPlatform::MovementControl(float DeltaTime)
{
  FVector CurrentLocation = GetActorLocation();
  float TotalDistance = FVector::Dist(GlobalStartLocation, GlobalTargetLocation);
  float Travelled = FVector::Dist(GlobalStartLocation, CurrentLocation);

  if (Travelled>=TotalDistance)
  {
    Swap(GlobalStartLocation, GlobalTargetLocation);
  }

  FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
  FVector NewLocation = CurrentLocation + Direction * Speed * DeltaTime;

  SetActorLocation(NewLocation);
}
