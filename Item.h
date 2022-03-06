#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Item.generated.h"

/**
 * 
 /
UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class INVENTORYSYSTEM_API UItem : public UObject
{
    GENERATED_BODY()

public:
    UItem();
    // The text for using the item.
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
        FText UseActionText;

    // The mesh to display this item's pickup.
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
        class UStaticMesh PickupMesh;

    // The thumbnail for this item.
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item")
        class UTexture2D* Thumbnail;

    // The display name for item in inventory.
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
        FText ItemDisplayName;

    // An optional discription for item.
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (MultiLine = true))
        FText ItemDescription;

    // The weight of the item.
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
        float Weight;

    UPROPERTY()
        class UInventoryComponent* OwningInventory;

    virtual void Use(class AInventorySystemCharacter* Character) PURE_VIRTUAL(UItem, )



    UFUNCTION(BlueprintImplementableEvent)
        void OnUse(class AInventorySystemCharacter* Character);
};