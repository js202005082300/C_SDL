@echo off

if exist ".\bin\prog.exe" ( del .\bin\prog.exe )

make

if exist ".\bin\prog.exe" ( .\bin\prog.exe )

@echo on
exit