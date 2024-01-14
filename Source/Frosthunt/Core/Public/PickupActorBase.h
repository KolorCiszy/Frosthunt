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

	UFUNCTION(BlueprintPure, Category="Pickup Actor Base")
	UStaticMeshComponent* GetMesh() const
	{
		return Mesh;
	}

	UFUNCTION(BlueprintPure, Category = "Pickup Actor Base")
	UBoxComponent* GetCollisionBox() const
	{
		return CollisionBox;
	}
	UFUNCTION(BlueprintPure, Category = "Pickup Actor Base")
	bool GetDestroyOnPickup() const	
	{
		return bDestroyOnPickup;
	}
private:

	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBoxComponent> CollisionBox;

	UPROPERTY(EditAnywhere)
	bool bDestroyOnPickup;

};
