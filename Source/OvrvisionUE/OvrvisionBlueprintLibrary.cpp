// Fill out your copyright notice in the Description page of Project Settings.

#include "OvrvisionUE.h"
#include "OvrvisionBlueprintLibrary.h"

#include "IOvrvisionPlugin.h"

//UOvrvisionBlueprintLibrary
/*
UOvrvisionBlueprintLibrary::UOvrvisionBlueprintLibrary()
{
	OvrvisionLeftTexture = NULL;
	OvrvisionRightTexture = NULL;

	GetImageWidth = 0;
	GetImageHeight = 0;
	GetImageAspectH = 0.0f;

	GetFocalPoint = 0.0f;
	GetHMDRightGap.Set(0.0f, 0.0f, 0.0f);
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

}
*/
namespace {

	UTexture2D* OvrvisionLeftTexture;
	UTexture2D* OvrvisionRightTexture;
}

void UOvrvisionBlueprintLibrary::OpenOvrvision(int32 openType, float ar_size)
{
	IOvrvisionPlugin::Get().Open(openType, 0.0f);
	OvrvisionLeftTexture = IOvrvisionPlugin::Get().GetTextureLeft();
	OvrvisionRightTexture = IOvrvisionPlugin::Get().GetTextureRight();

	/*
	GetImageWidth = IOvrvisionPlugin::Get().GetImageWidth();
	GetImageHeight = IOvrvisionPlugin::Get().GetImageHeight();
	GetImageAspectH = (float)GetImageHeight / (float)GetImageWidth;

	GetFocalPoint = IOvrvisionPlugin::Get().GetFocalPoint();
	GetHMDRightGap.X = IOvrvisionPlugin::Get().GetHMDRightGap(0);
	GetHMDRightGap.Y = IOvrvisionPlugin::Get().GetHMDRightGap(1);
	GetHMDRightGap.Z = IOvrvisionPlugin::Get().GetHMDRightGap(2);
	*/
}

void UOvrvisionBlueprintLibrary::CloseOvrvision()
{
	IOvrvisionPlugin::Get().Close();
}

void UOvrvisionBlueprintLibrary::UpdateOvrvision()
{
	IOvrvisionPlugin::Get().UpdateImage();
}

UTexture2D* UOvrvisionBlueprintLibrary::GetLeftEye()
{
	return OvrvisionLeftTexture;
}

UTexture2D* UOvrvisionBlueprintLibrary::GetRightEye()
{
	return OvrvisionRightTexture;
}



