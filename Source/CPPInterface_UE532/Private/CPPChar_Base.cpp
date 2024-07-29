#include "CPPChar_Base.h"

ACPPChar_Base::ACPPChar_Base(){
	PrimaryActorTick.bCanEverTick = true;
}

void ACPPChar_Base::BeginPlay(){
	Super::BeginPlay();
}

void ACPPChar_Base::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
}

void ACPPChar_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent){
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

