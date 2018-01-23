// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ModuleManager.h"

class FBT_OpenCVMLModule : public IModuleInterface
{
public:

	/**
	* Singleton-like access to this module's interface.  This is just for convenience!
	* Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
	*
	* @return Returns singleton instance, loading the module on demand if needed
	*/
	static inline FBT_OpenCVMLModule& Get()
	{
		return FModuleManager::LoadModuleChecked< FBT_OpenCVMLModule >("BT_OpenCVML");
	}

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	FORCEINLINE bool IsOpenCVReady() { return bIsOpenCVReady; }

private:
	/** Handle to the test dll we will load */
	void*	ExampleLibraryHandle;

	TMap<FString, void*> OpenCVLibsHandles;

	bool bIsOpenCVReady = false;
};