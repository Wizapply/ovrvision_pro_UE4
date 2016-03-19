// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "OvrvisionPluginHUD.generated.h"

//Define
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
 * 
 */
UCLASS()
class OVRVISIONUE_API AOvrvisionPluginHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	AOvrvisionPluginHUD();

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
