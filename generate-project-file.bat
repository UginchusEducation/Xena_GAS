@echo off

call "%~dp0\Utils\my-config.bat"

echo "Run Version Selector"
echo %VersionSelector%
echo %ProjectPath%
echo %MyEnginePath%
%VersionSelector% -switchversionsilent %ProjectPath% %MyEnginePath%

echo "Run Auto Build Tool"
%UBTRelativePath% -projectfiles -progress -project=%ProjectPath%
:: -game -engine // flags for source engine code 