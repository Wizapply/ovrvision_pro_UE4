// Fill out your copyright notice in the Description page of Project Settings.

#include "OvrvisionUE.h"
#include "OvrvisionPluginCharacter.h"

#include "IOvrvisionPlugin.h"

// Sets default values
AOvrvisionPluginCharacter::AOvrvisionPluginCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OvrvisionLeftTexture = NULL;
	OvrvisionRightTexture = NULL;

	GetImageWidth = 0;
	GetImageHeight = 0;
	GetImageAspectH = 0.0f;

	GetFocalPoint = 0.0f;
	GetHMDRightGap.Set(0.0f, 0.0f, 0.0f);
}

// Called when the game starts or when spawned
void AOvrvisionPluginCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOvrvisionPluginCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AOvrvisionPluginCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void AOvrvisionPluginCharacter::OpenOvrvision(int32 openType, float ar_size)
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

void AOvrvisionPluginCharacter::CloseOvrvision()
{
	IOvrvisionPlugin::Get().Close();
}

void  AOvrvisionPluginCharacter::UpdateOvrvision()
{
	IOvrvisionPlugin::Get().UpdateImage();
}
