// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "OvrvisionBlueprintLibrary.generated.h"

/**
 * 
 */
UCLASS()
class OVRVISIONUE_API UOvrvisionBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
private:
	UFUNCTION(BlueprintCallable, Category = "Ovrvision")
	static void OpenOvrvision(int32 openType, float ar_size);
	UFUNCTION(BlueprintCallable, Category = "Ovrvision")
	static void CloseOvrvision();
	UFUNCTION(BlueprintCallable, Category = "Ovrvision")
	static void UpdateOvrvision();

	UFUNCTION(BlueprintPure, Category = "Ovrvision")
	static UTexture2D* GetLeftEye();
	UFUNCTION(BlueprintPure, Category = "Ovrvision")
	static UTexture2D* GetRightEye();

};
