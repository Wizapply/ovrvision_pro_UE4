// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ModuleManager.h"

#include "Engine.h"
#include "Runtime/Engine/Classes/Engine/Texture2D.h"

///// Define /////
//camera type select define
#define OV_CAM5MP_FULL  (0)     //2560x1920 @15fps x2
#define OV_CAM5MP_FHD   (1)		//1920x1080 @30fps x2
#define OV_CAMHD_FULL   (2)		//1280x960  @45fps x2
#define OV_CAMVR_FULL   (3) 	//960x950   @60fps x2
#define OV_CAMVR_WIDE   (4)		//1280x800  @60fps x2
#define OV_CAMVR_VGA    (5)		//640x480   @90fps x2
#define OV_CAMVR_QVGA   (6)		//320x240   @120fps x2
//camera select define
#define OV_CAMEYE_LEFT  (0)
#define OV_CAMEYE_RIGHT (1)
//renderer quality
#define OV_CAMQT_DMSRMP (0)     //Demosaic&remap Processing quality
#define OV_CAMQT_DMS    (1)		//Demosaic Processing quality
#define OV_CAMQT_NONE   (2)		//None Processing quality
//Ar Macro define
#define MARKERGET_MAXNUM10  (100) //max marker is 10
#define MARKERGET_ARG10     (10)
#define MARKERGET_RECONFIGURE_NUM   (10)

#define BUFFERSIZE_BGRA (4)

/**
 * The public interface to this module.  In most cases, this interface is only public to sibling modules 
 * within this plugin.
 */
class IOvrvisionPlugin : public IModuleInterface
{
public:
	static inline IOvrvisionPlugin& Get(){
		return FModuleManager::LoadModuleChecked< IOvrvisionPlugin >( "OvrvisionPlugin" );
	}
	static inline bool IsAvailable() {
		return FModuleManager::Get().IsModuleLoaded( "OvrvisionPlugin" );
	}

public:
	//Texture for UE4
	virtual UTexture2D* GetTextureLeft() = 0;
	virtual UTexture2D* GetTextureRight() = 0;

	//Control
	virtual void Open(int opentype, float ar_msize) = 0;
	virtual void Close() = 0;
	virtual void UpdateImage() = 0;

	//Propatry
	virtual void SetExposure(int value) = 0;
	virtual void SetGain(int value) = 0;
	virtual void SetBLC(int value) = 0;
	virtual void SetWhiteBalanceR(int value) = 0;
	virtual void SetWhiteBalanceG(int value) = 0;
	virtual void SetWhiteBalanceB(int value) = 0;
	virtual void SetWhiteBalanceAutoMode(bool value) = 0;

	virtual int GetExposure() = 0;
	virtual int GetGain() = 0;
	virtual int GetBLC() = 0;
	virtual int GetWhiteBalanceR() = 0;
	virtual int GetWhiteBalanceG() = 0;
	virtual int GetWhiteBalanceB() = 0;
	virtual bool GetWhiteBalanceAutoMode() = 0;

	virtual int GetImageWidth() = 0;
	virtual int GetImageHeight() = 0;
	virtual float GetFocalPoint() = 0;
	virtual float GetHMDRightGap(int at) = 0;	//0~2
};

