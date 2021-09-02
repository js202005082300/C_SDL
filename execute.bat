@echo off

if exist ".\bin\prog.exe" ( del .\bin\prog.exe )
timeout 2 /NOBREAK & cls
make
timeout 2 /NOBREAK
if exist ".\bin\prog.exe" ( .\bin\prog.exe )

@echo on
exit