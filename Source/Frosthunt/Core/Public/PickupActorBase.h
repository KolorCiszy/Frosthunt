// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupActorInterface.h"
#include "PickupActorBase.generated.h"

class UBoxComponent;

UCLASS(Abstract)
class FROSTHUNT_API APickupActorBase : public AActor, public IPickupActorInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupActorBase();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> CollisionBox;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bDestroyOnPickup;


	
};
