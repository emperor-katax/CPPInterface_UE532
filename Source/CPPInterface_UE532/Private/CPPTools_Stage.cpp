#include "CPPTools_Stage.h"

ACPPTools_Stage::ACPPTools_Stage(){
	PrimaryActorTick.bCanEverTick = true;
}

ACPPTools_Stage::ACPPTools_Stage(float time, float energy) {
	Energy = energy;
	ActiveTime = time;
}

void ACPPTools_Stage::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}


FString ACPPTools_Stage::StageTool_GetName(){
	return Tool_Name;
}


// C++ interface implementations ///////////////////////////////

void ACPPTools_Stage::CPPI_Tool_Action(ENTool_Action action_type = ENTool_Action::Activate) {
	if (action_type == ENTool_Action::Activate) StageTool_Activate();
	else StageTool_Pause();
}

void ACPPTools_Stage::CPPI_Tool_Data(int task_type = 0, bool bData_01 = false, int intData_01 = 0, float flData_01 = 0.f, float flData_02 = 0.f, float flData_03 = 0.f) {

	switch (task_type) { // task_type -> use Enum instead of int
	case 0:
		StageTool_SetType(intData_01);
		break;
	case 1:
		StageTool_Calibrate(flData_01, flData_02, flData_03);
		break;
	default:
		break;
	}
}
FString ACPPTools_Stage::I_GetName() {
	return Tool_Name;
}
