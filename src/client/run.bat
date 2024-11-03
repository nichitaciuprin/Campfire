@echo off
setlocal

@REM set arg1=%1
@REM set arg2=%2

@REM echo %arg1%
@REM echo %arg2%

echo y | gdb -q -ex=run -ex=backtrace -ex=quit --args build\CampfireClient.exe %1 %2