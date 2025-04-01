// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class JuegoEnRed : ModuleRules
{
	public JuegoEnRed(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
