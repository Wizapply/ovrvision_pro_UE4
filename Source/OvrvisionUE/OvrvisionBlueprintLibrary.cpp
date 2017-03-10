// Fill out your copyright notice in the Description page of Project Settings.

#include "OvrvisionUE.h"
#include "OvrvisionBlueprintLibrary.h"

#include "IOvrvisionPlugin.h"

namespace {

	UTexture2D* OvrvisionLeftTexture;
	UTexture2D* OvrvisionRightTexture;
}

void UOvrvisionBlueprintLibrary::OpenOvrvision(int32 openType, float ar_size)
{
	IOvrvisionPlugin::Get().Open(openType, 0.0f);
	OvrvisionLeftTexture = IOvrvisionPlugin::Get().GetTextureLeft();
	OvrvisionRightTexture = IOvrvisionPlugin::Get().GetTextureRight();
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



