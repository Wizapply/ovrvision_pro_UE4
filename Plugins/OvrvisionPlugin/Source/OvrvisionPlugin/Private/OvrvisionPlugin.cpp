// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "OvrvisionPluginPrivatePCH.h"

//LoadLibrary
extern "C" {
	typedef int(*ovOpen_ptr)(int, float, int);
	typedef int(*ovClose_ptr)();
	typedef void(*ovRelease_ptr)();
	typedef void(*ovPreStoreCamData_ptr)(int qt);
	typedef void(*ovGetCamImageBGRA_ptr)(unsigned char*, int);
	typedef unsigned char*(*ovGetCamImageBGRAPointer_ptr)(int);
	typedef void(*ovGetCamImageRGB_ptr)(unsigned char*, int);
	typedef void(*ovGetCamImageBGR_ptr)(unsigned char*, int);
	typedef void(*ovGetCamImageForUnity_ptr)(unsigned char*, unsigned char*);

	typedef void(*ovGetCamImageForUnityNative_ptr)(unsigned char*, unsigned char*);

	typedef int(*ovGetImageWidth_ptr)();
	typedef int(*ovGetImageHeight_ptr)();
	typedef int(*ovGetImageRate_ptr)();
	typedef int(*ovGetBufferSize_ptr)();
	typedef int(*ovGetPixelSize_ptr)();

	//Set camera properties
	typedef void(*ovSetExposure_ptr)(int);
	typedef void(*ovSetGain_ptr)(int);
	typedef void(*ovSetBLC_ptr)(int);
	typedef void(*ovSetWhiteBalanceR_ptr)(int);
	typedef void(*ovSetWhiteBalanceG_ptr)(int);
	typedef void(*ovSetWhiteBalanceB_ptr)(int);
	typedef void(*ovSetWhiteBalanceAuto_ptr)(bool);
	//Get camera properties
	typedef int(*ovGetExposure_ptr)();
	typedef int(*ovGetGain_ptr)();
	typedef int(*ovGetBLC_ptr)();
	typedef int(*ovGetWhiteBalanceR_ptr)();
	typedef int(*ovGetWhiteBalanceG_ptr)();
	typedef int(*ovGetWhiteBalanceB_ptr)();
	typedef bool(*ovGetWhiteBalanceAuto_ptr)();
	typedef float(*ovGetFocalPoint_ptr)();
	typedef float(*ovGetHMDRightGap_ptr)(int);

	typedef float(*ovSetCamSyncMode_ptr)(bool);

	////////////// Ovrvision AR System //////////////
	typedef void(*ovARRender_ptr)();
	typedef int(*ovARGetData_ptr)(float*, int);
	typedef void(*ovARSetMarkerSize_ptr)(int);
	typedef int(*ovARGetMarkerSize_ptr)();

	////////////// Ovrvision Tracking System //////////////
	//testing
	typedef void(*ovTrackRender_ptr)(bool, bool);
	typedef int(*ovGetTrackData_ptr)(float*);
	typedef void(*ovTrackingCalibReset_ptr)();

	////////////// Ovrvision Calibration //////////////
	typedef void(*ovCalibInitialize_ptr)(int, int, double);
	typedef int(*ovCalibClose_ptr)();
	typedef int(*ovCalibFindChess_ptr)();
	typedef void(*ovCalibSolveStereoParameter_ptr)();
	typedef int(*ovCalibGetImageCount_ptr)();

	//Ovrvision config save status
	typedef bool(*ovSaveCamStatusToEEPROM_ptr)();

	//////////////////////////////////////////////

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

	const int CalibrationImageNum = 25;
}

class FOvrvisionPlugin : public IOvrvisionPlugin
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	virtual UTexture2D* GetTextureLeft() override;
	virtual UTexture2D* GetTextureRight() override;

	//Control
	virtual void Open(int opentype, float ar_msize) override;
	virtual void Close() override;
	virtual void UpdateImage() override;

	//Propatry
	virtual void SetExposure(int value) override;
	virtual void SetGain(int value) override;
	virtual void SetBLC(int value) override;
	virtual void SetWhiteBalanceR(int value) override;
	virtual void SetWhiteBalanceG(int value) override;
	virtual void SetWhiteBalanceB(int value) override;
	virtual void SetWhiteBalanceAutoMode(bool value) override;

	virtual int GetExposure() override;
	virtual int GetGain() override;
	virtual int GetBLC() override;
	virtual int GetWhiteBalanceR() override;
	virtual int GetWhiteBalanceG() override;
	virtual int GetWhiteBalanceB() override;
	virtual bool GetWhiteBalanceAutoMode() override;

	virtual int GetImageWidth() override;
	virtual int GetImageHeight() override;
	virtual float GetFocalPoint() override;
	virtual float GetHMDRightGap(int at) override;
private:
	HINSTANCE hLibrary;
	bool isOpen;

	TWeakObjectPtr<UTexture2D> TextureLeft;
	TWeakObjectPtr<UTexture2D> TextureRight;

	int32 TextureWidth;
	int32 TextureHeight;

	void UpdateTextureFromCameraBuffer(TWeakObjectPtr<UTexture2D> tex, uint8* buffer, int width, int height, int depth);

private:
	ovOpen_ptr ovOpen;
	ovClose_ptr ovClose;
	ovRelease_ptr ovRelease;
	ovPreStoreCamData_ptr ovPreStoreCamData;
	ovGetCamImageBGRA_ptr ovGetCamImageBGRA;
	ovGetCamImageBGRAPointer_ptr ovGetCamImageBGRAPointer;
	ovGetCamImageRGB_ptr ovGetCamImageRGB;
	ovGetCamImageBGR_ptr ovGetCamImageBGR;
	ovGetCamImageForUnity_ptr ovGetCamImageForUnity;

	ovGetCamImageForUnityNative_ptr ovGetCamImageForUnityNative;

	ovGetImageWidth_ptr ovGetImageWidth;
	ovGetImageHeight_ptr ovGetImageHeight;
	ovGetImageRate_ptr ovGetImageRate;
	ovGetBufferSize_ptr ovGetBufferSize;
	ovGetPixelSize_ptr ovGetPixelSize;

	//Set camera properties
	ovSetExposure_ptr ovSetExposure;
	ovSetGain_ptr ovSetGain;
	ovSetBLC_ptr ovSetBLC;
	ovSetWhiteBalanceR_ptr ovSetWhiteBalanceR;
	ovSetWhiteBalanceG_ptr ovSetWhiteBalanceG;
	ovSetWhiteBalanceB_ptr ovSetWhiteBalanceB;
	ovSetWhiteBalanceAuto_ptr ovSetWhiteBalanceAuto;
	//Get camera properties
	ovGetExposure_ptr ovGetExposure;
	ovGetGain_ptr ovGetGain;
	ovGetBLC_ptr ovGetBLC;
	ovGetWhiteBalanceR_ptr ovGetWhiteBalanceR;
	ovGetWhiteBalanceG_ptr ovGetWhiteBalanceG;
	ovGetWhiteBalanceB_ptr ovGetWhiteBalanceB;
	ovGetWhiteBalanceAuto_ptr ovGetWhiteBalanceAuto;
	ovGetFocalPoint_ptr ovGetFocalPoint;
	ovGetHMDRightGap_ptr ovGetHMDRightGap;

	ovSetCamSyncMode_ptr ovSetCamSyncMode;

	////////////// Ovrvision AR System //////////////
	ovARRender_ptr ovARRender;
	ovARGetData_ptr ovARGetData;
	ovARSetMarkerSize_ptr ovARSetMarkerSize;
	ovARGetMarkerSize_ptr ovARGetMarkerSize;

	////////////// Ovrvision Tracking System //////////////
	//testing
	ovTrackRender_ptr ovTrackRender;
	ovGetTrackData_ptr ovGetTrackData;
	ovTrackingCalibReset_ptr ovTrackingCalibReset;

	////////////// Ovrvision Calibration //////////////
	ovCalibInitialize_ptr ovCalibInitialize;
	ovCalibClose_ptr ovCalibClose;
	ovCalibFindChess_ptr ovCalibFindChess;
	ovCalibSolveStereoParameter_ptr ovCalibSolveStereoParameter;
	ovCalibGetImageCount_ptr ovCalibGetImageCount;

	ovSaveCamStatusToEEPROM_ptr ovSaveCamStatusToEEPROM;
};

IMPLEMENT_MODULE(FOvrvisionPlugin, OvrvisionPlugin)

void FOvrvisionPlugin::StartupModule()
{
	hLibrary = LoadLibrary(TEXT("ovrvision.dll"));
	if (hLibrary != NULL)
	{
		ovOpen = reinterpret_cast<ovOpen_ptr>(::GetProcAddress(hLibrary, "ovOpen"));
		ovClose = reinterpret_cast<ovClose_ptr>(::GetProcAddress(hLibrary, "ovClose"));
		ovRelease = reinterpret_cast<ovRelease_ptr>(::GetProcAddress(hLibrary, "ovRelease"));

		ovPreStoreCamData = reinterpret_cast<ovPreStoreCamData_ptr>(::GetProcAddress(hLibrary, "ovPreStoreCamData"));
		ovGetCamImageBGRA = reinterpret_cast<ovGetCamImageBGRA_ptr>(::GetProcAddress(hLibrary, "ovGetCamImageBGRA"));
		ovGetCamImageBGRAPointer = reinterpret_cast<ovGetCamImageBGRAPointer_ptr>(::GetProcAddress(hLibrary, "ovGetCamImageBGRAPointer"));
		ovGetCamImageRGB = reinterpret_cast<ovGetCamImageRGB_ptr>(::GetProcAddress(hLibrary, "ovGetCamImageRGB"));
		ovGetCamImageBGR = reinterpret_cast<ovGetCamImageBGR_ptr>(::GetProcAddress(hLibrary, "ovGetCamImageBGR"));

		ovGetCamImageForUnity = NULL;
		ovGetCamImageForUnityNative = NULL;

		ovGetImageWidth = reinterpret_cast<ovGetImageWidth_ptr>(::GetProcAddress(hLibrary, "ovGetImageWidth"));
		ovGetImageHeight = reinterpret_cast<ovGetImageHeight_ptr>(::GetProcAddress(hLibrary, "ovGetImageHeight"));
		ovGetImageRate = reinterpret_cast<ovGetImageRate_ptr>(::GetProcAddress(hLibrary, "ovGetImageRate"));
		ovGetBufferSize = reinterpret_cast<ovGetBufferSize_ptr>(::GetProcAddress(hLibrary, "ovGetBufferSize"));
		ovGetPixelSize = reinterpret_cast<ovGetPixelSize_ptr>(::GetProcAddress(hLibrary, "ovGetPixelSize"));

		//Set camera properties
		ovSetExposure = reinterpret_cast<ovSetExposure_ptr>(::GetProcAddress(hLibrary, "ovSetExposure"));
		ovSetGain = reinterpret_cast<ovSetGain_ptr>(::GetProcAddress(hLibrary, "ovSetGain"));
		ovSetBLC = reinterpret_cast<ovSetBLC_ptr>(::GetProcAddress(hLibrary, "ovSetBLC"));
		ovSetWhiteBalanceR = reinterpret_cast<ovSetWhiteBalanceR_ptr>(::GetProcAddress(hLibrary, "ovSetWhiteBalanceR"));
		ovSetWhiteBalanceG = reinterpret_cast<ovSetWhiteBalanceG_ptr>(::GetProcAddress(hLibrary, "ovSetWhiteBalanceG"));
		ovSetWhiteBalanceB = reinterpret_cast<ovSetWhiteBalanceB_ptr>(::GetProcAddress(hLibrary, "ovSetWhiteBalanceB"));
		ovSetWhiteBalanceAuto = reinterpret_cast<ovSetWhiteBalanceAuto_ptr>(::GetProcAddress(hLibrary, "ovSetWhiteBalanceAuto"));
		//Get camera properties
		ovGetExposure = reinterpret_cast<ovGetExposure_ptr>(::GetProcAddress(hLibrary, "ovGetExposure"));
		ovGetGain = reinterpret_cast<ovGetGain_ptr>(::GetProcAddress(hLibrary, "ovGetGain"));
		ovGetBLC = reinterpret_cast<ovGetBLC_ptr>(::GetProcAddress(hLibrary, "ovGetBLC"));
		ovGetWhiteBalanceR = reinterpret_cast<ovGetWhiteBalanceR_ptr>(::GetProcAddress(hLibrary, "ovGetWhiteBalanceR"));
		ovGetWhiteBalanceG = reinterpret_cast<ovGetWhiteBalanceG_ptr>(::GetProcAddress(hLibrary, "ovGetWhiteBalanceG"));
		ovGetWhiteBalanceB = reinterpret_cast<ovGetWhiteBalanceB_ptr>(::GetProcAddress(hLibrary, "ovGetWhiteBalanceB"));
		ovGetWhiteBalanceAuto = reinterpret_cast<ovGetWhiteBalanceAuto_ptr>(::GetProcAddress(hLibrary, "ovGetWhiteBalanceAuto"));
		ovGetFocalPoint = reinterpret_cast<ovGetFocalPoint_ptr>(::GetProcAddress(hLibrary, "ovGetFocalPoint"));
		ovGetHMDRightGap = reinterpret_cast<ovGetHMDRightGap_ptr>(::GetProcAddress(hLibrary, "ovGetHMDRightGap"));

		ovSetCamSyncMode = reinterpret_cast<ovSetCamSyncMode_ptr>(::GetProcAddress(hLibrary, "ovSetCamSyncMode"));


		////////////// Ovrvision AR System //////////////
		ovARRender = reinterpret_cast<ovARRender_ptr>(::GetProcAddress(hLibrary, "ovARRender"));
		ovARGetData = reinterpret_cast<ovARGetData_ptr>(::GetProcAddress(hLibrary, "ovARGetData"));
		ovARSetMarkerSize = reinterpret_cast<ovARSetMarkerSize_ptr>(::GetProcAddress(hLibrary, "ovARSetMarkerSize"));
		ovARGetMarkerSize = reinterpret_cast<ovARGetMarkerSize_ptr>(::GetProcAddress(hLibrary, "ovARGetMarkerSize"));

		////////////// Ovrvision Tracking System //////////////
		//testing
		ovTrackRender = reinterpret_cast<ovTrackRender_ptr>(::GetProcAddress(hLibrary, "ovTrackRender"));
		ovGetTrackData = reinterpret_cast<ovGetTrackData_ptr>(::GetProcAddress(hLibrary, "ovGetTrackData"));;
		ovTrackingCalibReset = reinterpret_cast<ovTrackingCalibReset_ptr>(::GetProcAddress(hLibrary, "ovTrackingCalibReset"));

		////////////// Ovrvision Calibration //////////////
		//ovCalibInitialize_ptr ovCalibInitialize;
		//ovCalibClose_ptr ovCalibClose;
		//ovCalibFindChess_ptr ovCalibFindChess;
		//ovCalibSolveStereoParameter_ptr ovCalibSolveStereoParameter;
		//ovCalibGetImageCount_ptr ovCalibGetImageCount;

		//ovSaveCamStatusToEEPROM_ptr ovSaveCamStatusToEEPROM;

	}
	else
	{
		::MessageBox(NULL, TEXT("ovrvision.dll load error!"), TEXT("ovrvision.dll load error!"), MB_OK);
	}

	isOpen = false;
}

void FOvrvisionPlugin::ShutdownModule()
{
	if (hLibrary != NULL) {
		Close();

		FreeLibrary(hLibrary);
	}
}

void FOvrvisionPlugin::UpdateTextureFromCameraBuffer(TWeakObjectPtr<UTexture2D> tex, uint8* buffer, int width, int height, int depth)
{
	if (tex.IsValid())
	{
		//Dispatch to render thread here
		struct FUpdateTextureRegionsData
		{
			FTexture2DResource* Texture2DResource;
			int32 MipIndex;
			FUpdateTextureRegion2D Region;
			uint32 SrcPitch;
			uint32 SrcBpp;
			uint8* SrcData;
		};

		FUpdateTextureRegionsData* RegionData = new FUpdateTextureRegionsData;

		RegionData->Texture2DResource = (FTexture2DResource*)tex->Resource;
		RegionData->MipIndex = 0;
		RegionData->Region = FUpdateTextureRegion2D(0, 0, 0, 0, width, height);;
		RegionData->SrcPitch = (uint32)(depth * width);
		RegionData->SrcBpp = (uint32)depth;
		RegionData->SrcData = buffer;

		ENQUEUE_UNIQUE_RENDER_COMMAND_ONEPARAMETER(
			UpdateTextureRegionsData,
			FUpdateTextureRegionsData*, RegionData, RegionData,
			{
				int32 CurrentFirstMip = RegionData->Texture2DResource->GetCurrentFirstMip();

		if (RegionData->MipIndex >= CurrentFirstMip)
		{
			RHIUpdateTexture2D(RegionData->Texture2DResource->GetTexture2DRHI(),
				RegionData->MipIndex - CurrentFirstMip,
				RegionData->Region,
				RegionData->SrcPitch,
				RegionData->SrcData + RegionData->Region.SrcY * RegionData->SrcPitch + RegionData->Region.SrcX * RegionData->SrcBpp);
		}

		delete RegionData;
			});
	}
}

//Function

UTexture2D* FOvrvisionPlugin::GetTextureLeft()
{
	return TextureLeft.Get();
}

UTexture2D* FOvrvisionPlugin::GetTextureRight()
{
	return TextureRight.Get();
}

void FOvrvisionPlugin::Open(int opentype, float ar_msize)
{
	if (ovOpen(0, ar_msize, opentype) != 0)
	{
		::MessageBox(NULL, TEXT("Ovrvision Open Error!"), TEXT("Ovrvision Open Error!"), MB_OK);
		return;
	}

	ovSetCamSyncMode(false);

	TextureWidth = ovGetImageWidth();
	TextureHeight = ovGetImageHeight();

	TextureLeft = UTexture2D::CreateTransient(TextureWidth, TextureHeight);
	TextureLeft->CompressionSettings = TextureCompressionSettings::TC_VectorDisplacementmap;
	TextureLeft->SRGB = 0;
	TextureLeft->UpdateResource();

	TextureRight = UTexture2D::CreateTransient(TextureWidth, TextureHeight);
	TextureRight->CompressionSettings = TextureCompressionSettings::TC_VectorDisplacementmap;
	TextureRight->SRGB = 0;
	TextureRight->UpdateResource();

	isOpen = true;
}

void FOvrvisionPlugin::Close()
{
	TextureLeft.Reset();
	TextureRight.Reset();

	if (ovClose() == 0) {
		ovRelease();

		isOpen = false;
	}
}

void FOvrvisionPlugin::UpdateImage()
{
	if (!isOpen)
		return;

	ovPreStoreCamData(OV_CAMQT_DMSRMP);

	unsigned char* left_p = ovGetCamImageBGRAPointer(OV_CAMEYE_LEFT);
	unsigned char* right_p = ovGetCamImageBGRAPointer(OV_CAMEYE_RIGHT);

	UpdateTextureFromCameraBuffer(TextureLeft, left_p, TextureWidth, TextureHeight, BUFFERSIZE_BGRA);
	UpdateTextureFromCameraBuffer(TextureRight, right_p, TextureWidth, TextureHeight, BUFFERSIZE_BGRA);

	//AR

}

//Propatry
void FOvrvisionPlugin::SetExposure(int value) {
	if (!isOpen)
		return;
	ovSetExposure(value);
}
void FOvrvisionPlugin::SetGain(int value) {
	if (!isOpen)
		return;
	ovSetGain(value);
}
void FOvrvisionPlugin::SetBLC(int value) {
	if (!isOpen)
		return;
	ovSetBLC(value);
}
void FOvrvisionPlugin::SetWhiteBalanceR(int value) {
	if (!isOpen)
		return;
	ovSetWhiteBalanceR(value);
}
void FOvrvisionPlugin::SetWhiteBalanceG(int value) {
	if (!isOpen)
		return;
	ovSetWhiteBalanceG(value);
}
void FOvrvisionPlugin::SetWhiteBalanceB(int value) {
	if (!isOpen)
		return;
	ovSetWhiteBalanceB(value);
}
void FOvrvisionPlugin::SetWhiteBalanceAutoMode(bool value) {
	if (!isOpen)
		return;
	ovSetWhiteBalanceAuto(value);
}

int FOvrvisionPlugin::GetExposure() {
	if (!isOpen)
		return 0;
	return ovGetExposure();
}
int FOvrvisionPlugin::GetGain() {
	if (!isOpen)
		return 0;
	return ovGetGain();
}
int FOvrvisionPlugin::GetBLC() {
	if (!isOpen)
		return 0;
	return ovGetBLC();
}
int FOvrvisionPlugin::GetWhiteBalanceR() {
	if (!isOpen)
		return 0;
	return GetWhiteBalanceR();
}
int FOvrvisionPlugin::GetWhiteBalanceG() {
	if (!isOpen)
		return 0;
	return ovGetWhiteBalanceG();
}
int FOvrvisionPlugin::GetWhiteBalanceB() {
	if (!isOpen)
		return 0;
	return GetWhiteBalanceB();
}
bool FOvrvisionPlugin::GetWhiteBalanceAutoMode() {
	if (!isOpen)
		return false;
	return ovGetWhiteBalanceAuto();
}

int FOvrvisionPlugin::GetImageWidth() {
	if (!isOpen)
		return 0;
	return ovGetImageWidth();
}

int FOvrvisionPlugin::GetImageHeight() {
	if (!isOpen)
		return 0;
	return ovGetImageHeight();
}

float FOvrvisionPlugin::GetFocalPoint() {
	if (!isOpen)
		return 0;
	return ovGetFocalPoint();
}

float FOvrvisionPlugin::GetHMDRightGap(int at) {
	if (!isOpen)
		return 0;
	return ovGetHMDRightGap(at);
}