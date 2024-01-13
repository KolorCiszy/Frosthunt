// Fill out your copyright notice in the Description page of Project Settings.


#include "Frosthunt/Core/Public/PickupActorBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
APickupActorBase::APickupActorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision box"));
	SetRootComponent(Mesh);
	CollisionBox->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void APickupActorBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickupActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
