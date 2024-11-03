@echo off
setlocal

set deps=%~dp0..\..\deps

set flags=
set flags=%flags% -g3 -Og -std=c++17 -pthread -m64
set flags=%flags% -Werror -Wno-missing-braces -Wall

set src=
set src=%src% %deps%\corelib\src\SysHelper.c
set src=%src% %deps%\corelib\src\SysNet.c

set include=
set include=%include% -I%~dp0src
set include=%include% -I%deps%\corelib\include

set lib=
set lib=%lib% -lWs2_32

if exist build rmdir /S /Q build
   mkdir build

g++ main.cpp %src% -o build/CampfireServer.exe %include% %lib% %flags%
