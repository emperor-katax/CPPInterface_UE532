#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h" 
#include "Engine/SpotLight.h"
#include "Components/SpotLightComponent.h"

#include "CPPChar_Civ.h"
#include "CPPChar_Enemy.h"
#include "CPPTools_Invent.h"
#include "CPPTools_Stage.h"

#include "CPPChar_Base.h"
#include "CPPTools_Base.h"

#include "CPP_Trigger_TypeA.generated.h"

UCLASS()
class CPPINTERFACE_UE532_API ACPP_Trigger_TypeA : public AActor{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_Trigger_TypeA();

	// Box collision element in BP
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Category = "KTX Trigger Property")
	UBoxComponent* Frame_Box;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Category = "KTX Trigger Property")
	USceneComponent* SceneComp;

	UFUNCTION()
	void OnEntering(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnLeaving(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	// ////////////////////// A  
	TArray<AActor*> Civilians;		// Arrays of CPPChar_Civ objects on stage.
	// TArray<ACPPChar_Civ*> Civilians; // <-- not working with UGameplayStatics::GetAllActorsOfClass
	TArray<AActor*> Enemies;		// Arrays of CPPChar_Enemy objects on stage. 
	TArray<AActor*> Inventory;		// Arrays of CPPTools_Invent objects on stage. 
	TArray<AActor*> StageTools;		// Arrays of CPPTools_Stage objects on stage.

};




