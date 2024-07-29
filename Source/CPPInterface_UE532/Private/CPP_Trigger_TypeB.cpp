#include "CPP_Trigger_TypeB.h"

ACPP_Trigger_TypeB::ACPP_Trigger_TypeB(){
	PrimaryActorTick.bCanEverTick = true;

	// setup actor
	Frame_Box = CreateDefaultSubobject<UBoxComponent>("Collision Box");
	SceneComp = CreateDefaultSubobject<USceneComponent>("Scene Component");
	RootComponent = SceneComp;
	Frame_Box->SetupAttachment(SceneComp, NAME_None);
	Frame_Box->bHiddenInGame = false;
	// bind functions to collision methods  
	Frame_Box->OnComponentBeginOverlap.AddDynamic(this, &ACPP_Trigger_TypeB::OnEntering);
	Frame_Box->OnComponentEndOverlap.AddDynamic(this, &ACPP_Trigger_TypeB::OnLeaving);

}

void ACPP_Trigger_TypeB::BeginPlay(){
	Super::BeginPlay();

	CollisionCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);

	UGameplayStatics::GetAllActorsWithInterface(GetWorld(), UCPPI_Tool::StaticClass(), ToolBase); // get CPPTools_Base actors 
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACPPChar_Base::StaticClass(), CharBase); // get CPPChar_Base actors
	
}

void ACPP_Trigger_TypeB::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
}


void ACPP_Trigger_TypeB::OnEntering(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	for (AActor* act : ToolBase) { // ToolBase is array of "Actor*"  
		if (act != nullptr) {
			// activate C++ interface from C++
			ICPPI_Tool* ReactingObject = Cast<ICPPI_Tool>(act); // cast to C++ interface ICPPI_Tool
			ReactingObject->CPPI_Tool_Data(0, true, 0, 0, 0, 0); // send data 
			ReactingObject->CPPI_Tool_Action(ENTool_Action::Activate); // send data 
			UE_LOG(LogTemp, Warning, TEXT(" -ktx    T II   OnEntering   stage tool name:  %s"), *(ReactingObject->I_GetName()));// get data
			
			// activate BP interface from C++ 
			ICPPI_Tool::Execute_CPPBPI_ShowPlayerName(act, GetPlayerName(OtherActor)); // send data
		}
	}
}

void ACPP_Trigger_TypeB::OnLeaving(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {

	for (AActor* act : ToolBase) { // ToolBase is an array of "Actor*"  
		if (act != nullptr) {
			// activate C++ interface from C++
			ICPPI_Tool* ReactingObject = Cast<ICPPI_Tool>(act);// cast to C++ interface ICPPI_Tool
			ReactingObject->CPPI_Tool_Data(0, false, 0, 0, 0, 0);
			ReactingObject->CPPI_Tool_Action(ENTool_Action::Pause);

			// activate BP interface from C++ 
			ICPPI_Tool::Execute_CPPBPI_ShowPlayerName(act, ""); // send data
		}
	}
}

FString ACPP_Trigger_TypeB::GetPlayerName(AActor* Player){
	FString result = "";
	
	FProperty* SpecialProperty = Player->GetClass()->FindPropertyByName(TEXT("PlayerName"));
	if (SpecialProperty) {
		FString* ptrValue = SpecialProperty->ContainerPtrToValuePtr<FString>(Player); // get property as bool  
		if (ptrValue) {
			result = *ptrValue;
		}
	}	

	return result;
}

// interface access
// https://docs.unrealengine.com/4.26/en-US/ProgrammingAndScripting/GameplayArchitecture/Interfaces/




