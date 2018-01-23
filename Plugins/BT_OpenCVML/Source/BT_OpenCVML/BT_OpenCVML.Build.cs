// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class BT_OpenCVML : ModuleRules
{
    private string ModulePath
    {
        get { return ModuleDirectory; }
    }


    public BT_OpenCVML(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				"BT_OpenCVML/Public"
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"BT_OpenCVML/Private",
				// ... add other private include paths required here ...
			}
			);

        PublicDependencyModuleNames.AddRange(
			new string[]
			{
                "Projects",
				"Core",
                "Engine",
                "CoreUObject",
                "InputCore",
                "Slate",
                "SlateCore",

                "BT_OpenCVMLLibrary",
            }
            );
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);

    }
}
