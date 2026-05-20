@echo off
setlocal

set "MSYS2_MINGW64=C:\msys64\mingw64.exe"

if not exist "%MSYS2_MINGW64%" (
    echo MSYS2 MinGW64 launcher not found: %MSYS2_MINGW64%
    exit /b 1
)

for %%I in ("%MSYS2_MINGW64%") do set "MSYS2_ROOT=%%~dpI"
set "MSYS2_SHELL=%MSYS2_ROOT%msys2_shell.cmd"

if not exist "%MSYS2_SHELL%" (
    echo MSYS2 shell launcher not found: %MSYS2_SHELL%
    exit /b 1
)

if not exist "%~dp0build" mkdir "%~dp0build"
if not exist "%~dp0build\msys-home" mkdir "%~dp0build\msys-home"
if not exist "%~dp0build\msys-tmp" mkdir "%~dp0build\msys-tmp"

set "HOME=%~dp0build\msys-home"
"%MSYS2_SHELL%" -mingw64 -defterm -no-start -where "%~dp0" -shell bash -lc "export TMPDIR=$(pwd -W)/build/msys-tmp TMP=$(pwd -W)/build/msys-tmp TEMP=$(pwd -W)/build/msys-tmp; make windows %*"
exit /b %ERRORLEVEL%
