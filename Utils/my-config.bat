@echo off

:: User local path
set MyEnginePath=C:\Unreal\UE_5.3
set LauncherPath=C:\Program Files (x86)\Epic Games\Launcher
set ProjectRoot=C:\Users\n_uginchus\Documents\Unreal Projects\Xena
set Python="C:\Windows\py.exe"

:: Engine params
set UBTRelativePath=%MyEnginePath%\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe
set InstalledBuildXML=%UESourcePath%\Engine\Build\InstalledEngineBuild.xml
set RunUAT=%MyEnginePath%\Engine\Build\BatchFiles\RunUAT.bat
set MyEditor=%MyEnginePath%\Engine\Binaries\Win64\UnrealEditor.exe
set VersionSelector=%LauncherPath%\Engine\Binaries\Win64\UnrealVersionSelector.exe

:: Project params
set ProjectName=Xena
set ProjectFile=%ProjectName%.uproject
set ProjectPath="%ProjectRoot%\%ProjectFile%"

:: Build params
set Platform=Win64
set GameConfiguration=Development
set EditorConfiguration=Development Editor
set ArchDir=%ProjectRoot%\Build

:: Run params
set gamePath="%ArchDir%\Windows\%ProjectName%.exe"

:: Other params
set SourceCodePath=%ProjectRoot%\Source
set dirsToRemove=Intermediate DerivedDataCache Saved Binaries Build .vs Plugins\*\Binaries
set filesToRemove=*.sln
set zipPath="C:\Program Files\7-Zip\7z.exe"