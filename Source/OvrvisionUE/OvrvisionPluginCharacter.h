// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "OvrvisionPluginCharacter.generated.h"

UCLASS()
class OVRVISIONUE_API AOvrvisionPluginCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AOvrvisionPluginCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

protected:
	UFUNCTION(BlueprintCallable, Category = "Ovrvision")
		void OpenOvrvision(int32 openType, float ar_size);
	UFUNCTION(BlueprintCallable, Category = "Ovrvision")
		void CloseOvrvision();
	UFUNCTION(BlueprintCallable, Category = "Ovrvision")
		void UpdateOvrvision();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ovrvision")
		int32 GetImageWidth;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ovrvision")
		int32 GetImageHeight;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ovrvision")
		float GetImageAspectH;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ovrvision")
		float GetFocalPoint;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ovrvision")
		FVector GetHMDRightGap;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ovrvision")
	class UTexture2D* OvrvisionLeftTexture;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ovrvision")
	class UTexture2D* OvrvisionRightTexture;

	
};
