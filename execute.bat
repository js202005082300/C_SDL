@echo off

if exist ".\bin\prog.exe" ( del .\bin\prog.exe )
timeout 1 /NOBREAK & cls
make
timeout 1 /NOBREAK
if exist ".\bin\prog.exe" ( .\bin\prog.exe )

@echo on
exit