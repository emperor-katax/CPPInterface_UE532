#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h" 
#include "CPPChar_Base.generated.h"

UCLASS()
class CPPINTERFACE_UE532_API ACPPChar_Base : public ACharacter{
	GENERATED_BODY()

public:
	ACPPChar_Base();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
