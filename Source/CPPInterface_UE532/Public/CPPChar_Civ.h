#pragma once

#include "CoreMinimal.h"
#include "CPPChar_Base.h"
#include "CPPChar_Civ.generated.h"

UCLASS()
class CPPINTERFACE_UE532_API ACPPChar_Civ : public ACPPChar_Base{
	GENERATED_BODY()

public:
	ACPPChar_Civ(); // <-- optional from base class

	ACPPChar_Civ(FString name); // <-- add by developer IF default constructor exist

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "KTX Civilian Property", meta = (ExposeOnSpawn = "true")) 
	FString Char_Name;

	UFUNCTION(BlueprintImplementableEvent, Category = "KTX Civilian Event")
	void Civ_Setup(bool active, float health); 

	UFUNCTION(BlueprintImplementableEvent, Category = "KTX Civilian Event")
	void Civ_PerformAction(int actionType);

	UFUNCTION(BlueprintImplementableEvent, Category = "KTX Civilian Event")
	void Civ_Deactivate();

	FString Civ_GetName();

protected:
	virtual void BeginPlay() override;  // <-- optional from base class

public:
	virtual void Tick(float DeltaTime) override;  // <-- optional from base class
	
};
