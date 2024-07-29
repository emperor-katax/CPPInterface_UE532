#include "CPPChar_Civ.h"

ACPPChar_Civ::ACPPChar_Civ() {
	PrimaryActorTick.bCanEverTick = true;
}

ACPPChar_Civ::ACPPChar_Civ(FString name){
	Char_Name = name;
}

void ACPPChar_Civ::BeginPlay() {
	Super::BeginPlay();

}

void ACPPChar_Civ::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}


// /////////////////////////////////

FString ACPPChar_Civ::Civ_GetName(){
	return Char_Name;
}