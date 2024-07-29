#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h" 
#include "Engine/SpotLight.h"
#include "Components/SpotLightComponent.h"

#include "CPPChar_Base.h"
#include "CPPTools_Base.h"
#include "CPPI_Tool.h"

#include "CPP_Trigger_TypeB.generated.h"

UCLASS()
class CPPINTERFACE_UE532_API ACPP_Trigger_TypeB : public AActor{
	GENERATED_BODY()
	
public:	
	ACPP_Trigger_TypeB();

	// Box collision element in BP
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Category = "KTX Trigger Property")
	UBoxComponent* Frame_Box;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Category = "KTX Trigger Property")
	USceneComponent* SceneComp;

	UFUNCTION()
	void OnEntering(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnLeaving(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintImplementableEvent, Category = "KTX Trigger TypeB Event")
	void Util_GetName(const FString& name);  // <-- const and & must be use for FString

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



	ACharacter* CollisionCharacter = nullptr;	// Use for detect character in collision funtion
	FString GetPlayerName(AActor* Player);

	TArray<AActor*> ToolBase;		// Arrays of CPPTools_Base objects on stage. 
	TArray<AActor*> CharBase;		// Arrays of CPPChar_Base objects on stage.

};


// UObject
// https://docs.unrealengine.com/4.26/en-US/ProgrammingAndScripting/ProgrammingWithCPP/UnrealArchitecture/Objects/
// https://romeroblueprints.blogspot.com/2020/11/the-uobject-class.html
// https://ikrima.dev/ue4guide/engine-programming/uobjects/new-uobject-allocation-flow/
// https://dev.epicgames.com/community/snippets/Ele/unreal-engine-runtime-uobject-serialization


// property referncing
// https://docs.unrealengine.com/5.1/en-US/referencing-assets-in-unreal-engine/

