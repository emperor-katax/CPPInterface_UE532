#pragma once

#include "CoreMinimal.h"
#include "CPPChar_Base.h"
#include "CPPChar_Enemy.generated.h"

UCLASS()
class CPPINTERFACE_UE532_API ACPPChar_Enemy : public ACPPChar_Base{
	GENERATED_BODY()

public: // <-- dont forget put public: !

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "KTX Enemy Property", meta = (ExposeOnSpawn = "true"))
	FString Char_Name;

	UFUNCTION(BlueprintImplementableEvent, Category = "KTX Enemy Event")
	void Enm_Setup(bool active, float health, float range, float shield); 

	UFUNCTION(BlueprintImplementableEvent, Category = "KTX Enemy Event")
	void Enm_Attck(int attackType);	
	
	UFUNCTION(BlueprintImplementableEvent, Category = "KTX Enemy Event")
	void Enm_Defend(int DefendType);

	UFUNCTION(BlueprintImplementableEvent, Category = "KTX Enemy Event")
	void Enm_Deactivate();


	FString Enm_GetName();
	
};
