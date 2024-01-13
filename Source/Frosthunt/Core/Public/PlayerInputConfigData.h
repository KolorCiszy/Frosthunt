#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PlayerInputConfigData.generated.h"

class UInputAction;

/**
 * Stores pointers to Input Actions for native binding
*/
UCLASS()
class FROSTHUNT_API UPlayerInputConfigData : public UDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
        TObjectPtr<UInputAction> InputMove;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
        TObjectPtr<UInputAction> InputJump;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
        TObjectPtr<UInputAction> InputCrouch;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
        TObjectPtr<UInputAction> InputRun;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
        TObjectPtr<UInputAction> InputSprint;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
        TObjectPtr<UInputAction> InputLook;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
        TObjectPtr<UInputAction> InputLeftMouseButton;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
        TObjectPtr<UInputAction> InputRightMouseButton;
};