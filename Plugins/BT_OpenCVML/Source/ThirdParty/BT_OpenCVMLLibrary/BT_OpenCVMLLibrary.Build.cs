// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class BT_OpenCVMLLibrary : ModuleRules
{

    private string LibraryPath
    {
        get { return Path.GetFullPath(Path.Combine(ModuleDirectory, "lib")); }
    }

    private string GetLibraryPath(string LibName)
    {
        return Path.Combine(LibraryPath, LibName);
    }


    public BT_OpenCVMLLibrary(ReadOnlyTargetRules Target) : base(Target)
	{
		Type = ModuleType.External;

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
            // Include headers
            PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "include"));

            // Add the import library
            PublicLibraryPaths.Add(Path.Combine(ModuleDirectory, "x64", "Debug"));
			PublicAdditionalLibraries.Add("ExampleLibrary.lib");

            PublicLibraryPaths.Add(Path.Combine(ModuleDirectory, "lib"));

            PublicAdditionalLibraries.Add("opencv_core340d.lib");
            PublicAdditionalLibraries.Add("opencv_highgui340d.lib");
            PublicAdditionalLibraries.Add("opencv_imgproc340d.lib");
            PublicAdditionalLibraries.Add("opencv_imgcodecs340d.lib");
            PublicAdditionalLibraries.Add("opencv_ml340d.lib");
            PublicAdditionalLibraries.Add("opencv_videoio340d.lib");

            PublicDelayLoadDLLs.Add("opencv_core340d.dll");
            PublicDelayLoadDLLs.Add("opencv_highgui340d.dll");
            PublicDelayLoadDLLs.Add("opencv_imgproc340d.dll");
            PublicDelayLoadDLLs.Add("opencv_imgcodecs340d.dll");
            PublicDelayLoadDLLs.Add("opencv_ml340d.dll");
            PublicDelayLoadDLLs.Add("opencv_videoio340d.dll");

            // Delay-load the DLL, so we can load it from the right place first
            PublicDelayLoadDLLs.Add("ExampleLibrary.dll");
		}
	}
}
