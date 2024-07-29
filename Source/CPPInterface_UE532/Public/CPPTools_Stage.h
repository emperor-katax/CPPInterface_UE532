#pragma once

#include "CoreMinimal.h"
#include "CPPTools_Base.h"
#include "CPPTools_Stage.generated.h"

UCLASS()
class CPPINTERFACE_UE532_API ACPPTools_Stage : public ACPPTools_Base{
	GENERATED_BODY()

public:
	ACPPTools_Stage();  // <-- optional from base class

	ACPPTools_Stage(float time, float energy);   // <-- add by developer IF default constructor exist

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "KTX StageTool Property", meta = (ExposeOnSpawn = "true"))
	FString Tool_Name;

	UFUNCTION(BlueprintImplementableEvent, Category = "KTX StageTool station Event")
	void StageTool_Activate(); 

	UFUNCTION(BlueprintImplementableEvent, Category = "KTX StageTool station Event")
	void StageTool_Pause();

	UFUNCTION(BlueprintImplementableEvent, Category = "KTX StageTool station Event")
	void StageTool_SetType(int station_type);

	UFUNCTION(BlueprintImplementableEvent, Category = "KTX StageTool station Event")
	void StageTool_Calibrate(float time, float energy, float resource);

	FString StageTool_GetName();

	// ////////////////////////////////////////////////////////////
	// C++ interface implementation
	virtual void CPPI_Tool_Action(ENTool_Action action_type) ;
	virtual void CPPI_Tool_Data(
		int task_type,
		bool bData_01,
		int intData_01,
		float flData_01, float flData_02, float flData_03
	);
	virtual FString I_GetName();


public:
	virtual void Tick(float DeltaTime) override;  // <-- optional from base class

private:
	float Energy; 
	float ActiveTime; 
	
};
