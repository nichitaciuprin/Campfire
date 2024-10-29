@echo off
setlocal

set root=%~dp0..\..
set deps=%root%\deps
set batdir=%~dp0
set build=%batdir%build

@REM -O      Same as -O1
@REM -O0     do no optimize, the default if no optimization level is specified
@REM -O1     optimize minimally, favoring compilation time
@REM -O2     optimize more, without speed/size tradeoff
@REM -O3     optimize even more, favoring speed
@REM -Ofast  optimize very aggressively to the point of breaking standard compliance, favoring speed. May change program behavior
@REM -Og     optimize debugging experience. -Og enables optimizations that do not interfere with debugging. It should be the optimization level of choice for the standard edit-compile-debug cycle, offering a reasonable level of optimization while maintaining fast compilation and a good debugging experience.
@REM -Os     optimize for size. -Os enables all -O2 optimizations that do not typically increase code size. It also performs further optimizations designed to reduce code size. -Os disables the following optimization flags: -falign-functions -falign-jumps -falign-loops -falign-labels -freorder-blocks -freorder-blocks-and-partition -fprefetch-loop-arrays -ftree-vect-loop-version

set flags=-g3 -Og -Werror -Wall -std=c++17 -Wno-missing-braces -pthread -m64

@REM set lib=
@REM set lib=%lib% -lWs2_32

set include=
set include=%include% -I%deps%\Base\include
set include=%include% -I%deps%\Sys\include
set include=%include% -I%~dp0src

set src=
set src=%src% %deps%\Sys\src\SysHelper.c
set src=%src% %deps%\Sys\src\SysWindow.c
set src=%src% %deps%\Sys\src\SysNet.c

if exist %build% rmdir /S /Q %build%
   mkdir %build%

g++ main.cpp %src% -o build/CampfireServer.exe %flags% %include% %lib% -lgdi32 -lwinmm -lWs2_32
