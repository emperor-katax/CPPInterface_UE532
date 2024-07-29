#include "CPPI_Tool.h"

void ICPPI_Tool::CPPI_Tool_InterfaceSupport(ENTool_Task task_mode, int task_type, bool bData_01, int intData_01, float flData_01, float flData_02, float flData_03){
	UE_LOG(LogTemp, Warning, TEXT("ktx	   +++[interface called]+++     -- ICPPI_Tool >>  CPPI_Tool_InterfaceSupport"));
}


void ICPPI_Tool::CPPI_Tool_Action(ENTool_Action action_type){
	UE_LOG(LogTemp, Warning, TEXT("ktx	   +++[interface called]+++     -- ICPPI_Tool >>  CPPI_Tool_Action"));
}

void ICPPI_Tool::CPPI_Tool_Data(int task_type, bool bData_01, int intData_01, float flData_01, float flData_02, float flData_03){
	UE_LOG(LogTemp, Warning, TEXT("ktx	   +++[interface called]+++     -- ICPPI_Tool >>  CPPI_Tool_Data"));
}



// approach 3

void ICPPI_Tool::Invent_Activate(bool Active){}
void ICPPI_Tool::Invent_Pause(){}
void ICPPI_Tool::Invent_Option(int option){}
void ICPPI_Tool::StageTool_Activate(){}
void ICPPI_Tool::StageTool_Pause(){}
void ICPPI_Tool::StageTool_SetType(int station_type){}
void ICPPI_Tool::StageTool_Calibrate(float time, float energy, float resource){}

FString ICPPI_Tool::I_GetName(){
	return "";
}





