// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "BT_OpenCVML.h"
#include "Core.h"
#include "ModuleManager.h"
#include "IPluginManager.h"
#include "ExampleLibrary.h"

#define LOCTEXT_NAMESPACE "FBT_OpenCVMLModule"

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgcodecs.hpp"

#include <iostream>
#include <sstream>

void FBT_OpenCVMLModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// Get the base directory of this plugin
	FString BaseDir = IPluginManager::Get().FindPlugin("BT_OpenCVML")->GetBaseDir();

	// Add on the relative location of the third party dll and load it
	FString LibraryPath;
#if PLATFORM_WINDOWS
	LibraryPath = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/BT_OpenCVMLLibrary/Win64/ExampleLibrary.dll"));
#endif // PLATFORM_WINDOWS

	ExampleLibraryHandle = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;

	if (ExampleLibraryHandle)
	{
		// Call the test function in the third party library that opens a message box
		//FString MapImage = FPaths::Combine(*BaseDir, TEXT("Resources/map.jpg"));
		//ExampleLibraryFunction(TCHAR_TO_ANSI(*MapImage));
	}
	else
	{
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("ThirdPartyLibraryError", "Failed to load example third party library"));
	}

	// Load OpenCV dll's
	OpenCVLibsHandles.Add("opencv_core340d", nullptr);
	OpenCVLibsHandles.Add("opencv_highgui340d", nullptr);
	OpenCVLibsHandles.Add("opencv_imgproc340d", nullptr);
	OpenCVLibsHandles.Add("opencv_imgcodecs340d", nullptr);
	OpenCVLibsHandles.Add("opencv_ml340d", nullptr);
	OpenCVLibsHandles.Add("opencv_videoio340d", nullptr);


	for (auto& Val : OpenCVLibsHandles)
	{
		FString FilePath = FString::Printf(TEXT("Binaries/Win64/%s.dll"), *Val.Key);

		FString LibraryPath = FPaths::Combine(*BaseDir, FilePath);
		Val.Value = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;

		if (Val.Value)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s loaded"), *Val.Key);

			bIsOpenCVReady = true;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("%s not loaded"), *Val.Key);

			bIsOpenCVReady = false;
		}
	}


	// test open CV
	if (bIsOpenCVReady)
	{
		cv::Mat M(2, 2, CV_8UC3, cv::Scalar(0, 0, 255));

		std::ostringstream Log;
		Log << "M = " << std::endl << " " << M << std::endl << std::endl;

		
		UE_LOG(LogTemp, Warning, TEXT("3> TEST open CV %s"), *FString(Log.str().c_str()));
	}
}

void FBT_OpenCVMLModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// Free the dll handle
	FPlatformProcess::FreeDllHandle(ExampleLibraryHandle);
	ExampleLibraryHandle = nullptr;

	// Free the dll handle
	for (auto& Val : OpenCVLibsHandles)
	{
		FPlatformProcess::FreeDllHandle(Val.Value);
		Val.Value = nullptr;
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FBT_OpenCVMLModule, BT_OpenCVML)