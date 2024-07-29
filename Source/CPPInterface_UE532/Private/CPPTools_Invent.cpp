#include "CPPTools_Invent.h"

FString ACPPTools_Invent::Invent_GetName(){
	return Tool_Name;
}


// C++ interface implementations ///////////////////////////////

void ACPPTools_Invent::CPPI_Tool_Action(ENTool_Action action_type = ENTool_Action::Activate){
	if (action_type == ENTool_Action::Pause) Invent_Pause();
}

void ACPPTools_Invent::CPPI_Tool_Data(int task_type = 0, bool bData_01 = false, int intData_01 = 0, float flData_01 = 0.f, float flData_02 = 0.f, float flData_03 = 0.f){

	switch (task_type) { // task_type -> use Enum instead of int
	case 0:
		Invent_Activate(bData_01);
		break;
	case 1:
		Invent_Option(intData_01);
		break;
	default:
		break;
	}
}

FString ACPPTools_Invent::I_GetName(){
	return Tool_Name;
}
