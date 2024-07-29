#include "CPP_Trigger_TypeA.h"

ACPP_Trigger_TypeA::ACPP_Trigger_TypeA(){
 	PrimaryActorTick.bCanEverTick = true;
	
	// setup actor
	Frame_Box = CreateDefaultSubobject<UBoxComponent>("Collision Box"); 
	SceneComp = CreateDefaultSubobject<USceneComponent>("Scene Component");
	RootComponent = SceneComp;
	Frame_Box->SetupAttachment(SceneComp,NAME_None);
	Frame_Box->bHiddenInGame = false;
	// bind functions to collision methods  
	Frame_Box->OnComponentBeginOverlap.AddDynamic(this, &ACPP_Trigger_TypeA::OnEntering);
	Frame_Box->OnComponentEndOverlap.AddDynamic(this, &ACPP_Trigger_TypeA::OnLeaving);

}

void ACPP_Trigger_TypeA::BeginPlay(){
	Super::BeginPlay();
	
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACPPChar_Civ::StaticClass(), Civilians); // get CPPChar_Civ actors 
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACPPChar_Enemy::StaticClass(), Enemies); // get CPPChar_Enemy actors 
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACPPTools_Invent::StaticClass(), Inventory); // get CPPTools_Invent actors 
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACPPTools_Stage::StaticClass(), StageTools); // get CPPTools_Stage actors 
	
}

void ACPP_Trigger_TypeA::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
}


void ACPP_Trigger_TypeA::OnEntering(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	for (AActor* act : Civilians) { // Civilians is array of "Actor*" 
		ACPPChar_Civ* civ = Cast<ACPPChar_Civ>(act); // cast CPPChar_Civ as an actors from Civilians array

		if (civ != nullptr) civ->Civ_PerformAction(12000);
		UE_LOG(LogTemp, Warning, TEXT(" -ktx   T I    Enter   civilians:  %s"), *(civ->Civ_GetName()));
	}


	for (AActor* act : Enemies) { // Enemies is array of "Actor*" 
		ACPPChar_Enemy* en = Cast<ACPPChar_Enemy>(act); // cast CPPChar_Enemy as an actors from Enemies array

		if (en != nullptr) en->Enm_Attck(2);
		if (en != nullptr) en->Enm_Defend(3);
		UE_LOG(LogTemp, Warning, TEXT(" -ktx   T I    Enter   enemies:  %s"), *(en->Enm_GetName()));
	}

	for (AActor* act : Inventory) { // Inventory is array of "Actor*" 
		ACPPTools_Invent* inv = Cast<ACPPTools_Invent>(act); // cast CPPTools_Invent as an actors from Inventory array

		if (inv != nullptr) inv->Invent_Activate(true);
		UE_LOG(LogTemp, Warning, TEXT(" -ktx   T I    Enter   inventory:  %s"), *(inv->Invent_GetName()));
	}

	for (AActor* act : StageTools) { // StageTools is array of "Actor*" 
		ACPPTools_Stage* sgt = Cast<ACPPTools_Stage>(act); // cast CPPTools_Stage as an actors from StageTools array

		if (sgt != nullptr) sgt->StageTool_Activate();
		UE_LOG(LogTemp, Warning, TEXT(" -ktx   T I    Enter   stage tool:  %s"), *(sgt->StageTool_GetName()));
	}

}

void ACPP_Trigger_TypeA::OnLeaving(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {

	for (AActor* act : Civilians) { // Civilians is array of "Actor*" 
		ACPPChar_Civ* civ = Cast<ACPPChar_Civ>(act); // cast CPPChar_Civ as an actors from Civilians array 

		if (civ != nullptr) civ->Civ_PerformAction(0);
		UE_LOG(LogTemp, Warning, TEXT(" -ktx   T I   L    civilians:  %s"), *(civ->Civ_GetName()));
	}


	for (AActor* act : Enemies) { // Enemies is array of "Actor*" 
		ACPPChar_Enemy* en = Cast<ACPPChar_Enemy>(act); // cast CPPChar_Enemy as an actors from Enemies array

		if (en != nullptr) en->Enm_Deactivate();
		UE_LOG(LogTemp, Warning, TEXT(" -ktx   T I   L    enemies:  %s"), *(en->Enm_GetName()));
	}

	for (AActor* act : Inventory) { // Inventory is array of "Actor*" 
		ACPPTools_Invent* inv = Cast<ACPPTools_Invent>(act); // cast CPPTools_Invent as an actors from Inventory array

		if (inv != nullptr) inv->Invent_Activate(false);
		UE_LOG(LogTemp, Warning, TEXT(" -ktx   T I   L    inventory:  %s"), *(inv->Invent_GetName()));
	}

	for (AActor* act : StageTools) { // StageTools is array of "Actor*" 
		ACPPTools_Stage* sgt = Cast<ACPPTools_Stage>(act); // cast CPPTools_Stage as an actors from StageTools array

		if (sgt != nullptr) sgt->StageTool_Pause();
		UE_LOG(LogTemp, Warning, TEXT(" -ktx   T I   L    stage tool:  %s"), *(sgt->StageTool_GetName()));
	}


	//FProperty* SpecialProperty = OtherActor->GetClass()->FindPropertyByName(TEXT("Flag_01"));
	//if (SpecialProperty) {
	//	bool* ptrValue = SpecialProperty->ContainerPtrToValuePtr<bool>(OtherActor); // get property as bool  
	//	if (ptrValue) {
	//		bool temp = *ptrValue;
	//		if (temp) {
	//			UE_LOG(LogTemp, Warning, TEXT(" - dakt --- %s"), *(OtherActor->GetName()));
	//			CheckObjects();
	//		}
	//	}
	//}
}


// UE_LOG notes
// UE_LOG(LogTemp, Warning, TEXT("Text, %d %f %s"), intVar, floatVar, *fstringVar );
// UE_LOG(YourLog,Warning,TEXT("MyCharacter's Bool is %s"), (MyCharacter->MyBool ? TEXT("True") : TEXT("False")));
// UE_LOG(YourLog,Warning,TEXT("MyCharacter's Location is %s"), *MyCharacter->GetActorLocation().ToString());
// https://www.chrismccole.com/blog/logging-in-ue4-cpp




