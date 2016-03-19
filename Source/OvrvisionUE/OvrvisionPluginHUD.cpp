// Fill out your copyright notice in the Description page of Project Settings.

#include "OvrvisionUE.h"
#include "OvrvisionPluginHUD.h"

#include "IOvrvisionPlugin.h"

AOvrvisionPluginHUD::AOvrvisionPluginHUD()
{
	OvrvisionLeftTexture = NULL;
	OvrvisionRightTexture = NULL;

	GetImageWidth = 0;
	GetImageHeight = 0;
	GetImageAspectH = 0.0f;

	GetFocalPoint = 0.0f;
	GetHMDRightGap.Set(0.0f, 0.0f, 0.0f);
}

void AOvrvisionPluginHUD::OpenOvrvision(int32 openType, float ar_size)
{
	IOvrvisionPlugin::Get().Open(openType, 0.0f);
	OvrvisionLeftTexture = IOvrvisionPlugin::Get().GetTextureLeft();
	OvrvisionRightTexture = IOvrvisionPlugin::Get().GetTextureRight();

	GetImageWidth = IOvrvisionPlugin::Get().GetImageWidth();
	GetImageHeight = IOvrvisionPlugin::Get().GetImageHeight();
	GetImageAspectH = (float)GetImageHeight / (float)GetImageWidth;

	GetFocalPoint = IOvrvisionPlugin::Get().GetFocalPoint();
	GetHMDRightGap.X = IOvrvisionPlugin::Get().GetHMDRightGap(0);
	GetHMDRightGap.Y = IOvrvisionPlugin::Get().GetHMDRightGap(1);
	GetHMDRightGap.Z = IOvrvisionPlugin::Get().GetHMDRightGap(2);
}

void AOvrvisionPluginHUD::CloseOvrvision()
{
	IOvrvisionPlugin::Get().Close();
}

void  AOvrvisionPluginHUD::UpdateOvrvision()
{
	IOvrvisionPlugin::Get().UpdateImage();
}
