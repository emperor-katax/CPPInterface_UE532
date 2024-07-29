#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CPPI_Tool.generated.h"

UINTERFACE(MinimalAPI)
class UCPPI_Tool : public UInterface{
	GENERATED_BODY()
};

// //////////// ENUMs /////////////////
UENUM(BlueprintType)
enum ENTool_Task{
	Action,
	Data
};

UENUM(BlueprintType)
enum ENTool_Action {
	Activate,
	Pause
};



class CPPINTERFACE_UE532_API ICPPI_Tool{
	GENERATED_BODY()

public:

	// BP interface ////////////////////////////////
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "C++ GetName Interface")
	void CPPBPI_ShowPlayerName(const FString& password);


	// C++ interface //////////////////////////////
	// -- approach 1 - send all data from 1 interface
	virtual void CPPI_Tool_InterfaceSupport(
		ENTool_Task task_mode,
		int task_type,
		bool bData_01, 
		int intData_01, 
		float flData_01, float flData_02, float flData_03 
		);

	// -- approach 2 - group interfaces depends on tasks
	virtual void CPPI_Tool_Action(ENTool_Action action_type);
	virtual void CPPI_Tool_Data(
		int task_type, 
		bool bData_01,
		int intData_01,
		float flData_01, float flData_02, float flData_03);

	// -- approach 3 - make unique interface for each task
	virtual void Invent_Activate(bool Active);
	virtual void Invent_Pause(); 
	virtual void Invent_Option(int option);

	virtual void StageTool_Activate(); 
	virtual void StageTool_Pause(); 
	virtual void StageTool_SetType(int station_type);
	virtual void StageTool_Calibrate(float time, float energy, float resource);


	virtual FString I_GetName(); // return data
	
	//virtual FString I_GetName() = 0; // <-- MUST be implemented in child classes
};

/*

list of methods/events from childrens of Tools_Base class
inventory
	void Invent_Activate(bool Active); 
	void Invent_Pause(); // action
	void Invent_Option(int option);

stage tools
	void StageTool_Activate(); // action
	void StageTool_Pause(); // action
	void StageTool_SetType(int station_type);
	void StageTool_Calibrate(float time, float energy, float resource);

common
	FString ##_GetName();

*/
