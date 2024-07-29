#include "CPPTools_Base.h"

ACPPTools_Base::ACPPTools_Base(){
	PrimaryActorTick.bCanEverTick = true;
	
	// setup actor
	Frame_Box = CreateDefaultSubobject<UBoxComponent>("Collision Box");
	SceneComp = CreateDefaultSubobject<USceneComponent>("Scene Component");
	RootComponent = SceneComp;
	Frame_Box->SetupAttachment(SceneComp,NAME_None);
	Frame_Box->bHiddenInGame = false;

}

void ACPPTools_Base::BeginPlay(){
	Super::BeginPlay();
}

void ACPPTools_Base::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
}

