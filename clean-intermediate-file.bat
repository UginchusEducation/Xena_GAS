@echo off

call "%~dp0\Utils\my-config.bat"

pushd "%ProjectRoot%"
FOR %%f in (%dirsToRemove%) do (
    rmdir /s /q %%f
)

FOR %%f in (%filesToRemove%) do (
    del /q %%f
)

popd