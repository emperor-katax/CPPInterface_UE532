#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h" 
#include "CPPI_Tool.h" 
#include "CPPTools_Base.generated.h"

UCLASS()
class CPPINTERFACE_UE532_API ACPPTools_Base : public AActor, public ICPPI_Tool {
	GENERATED_BODY()
	
public:	
	ACPPTools_Base(); 

	// Box collision element in BP
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced)
	UBoxComponent* Frame_Box;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced)
	USceneComponent* SceneComp;

protected:
	virtual void BeginPlay() override; 

public:	
	virtual void Tick(float DeltaTime) override;

};
