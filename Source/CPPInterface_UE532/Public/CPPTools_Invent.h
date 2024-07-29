#pragma once

#include "CoreMinimal.h"
#include "CPPTools_Base.h"
#include "CPPTools_Invent.generated.h"

UCLASS()
class CPPINTERFACE_UE532_API ACPPTools_Invent : public ACPPTools_Base{
	GENERATED_BODY()

public:  // <-- dont forget put public: !

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "KTX Inventory Property", meta = (ExposeOnSpawn = "true"))
	FString Tool_Name;

	UFUNCTION(BlueprintImplementableEvent, Category = "KTX Inventory Event")
	void Invent_Activate(bool Active); 

	UFUNCTION(BlueprintImplementableEvent, Category = "KTX Inventory Event")
	void Invent_Pause(); 

	UFUNCTION(BlueprintImplementableEvent, Category = "KTX Inventory Event")
	void Invent_Option(int option); 

	FString Invent_GetName();

	// ////////////////////////////////////////////////////////////
	// C++ interface implementation
	virtual void CPPI_Tool_Action(ENTool_Action action_type);
	virtual void CPPI_Tool_Data(
		int task_type,
		bool bData_01,
		int intData_01,
		float flData_01, float flData_02, float flData_03
	);	
	virtual FString I_GetName();

};
