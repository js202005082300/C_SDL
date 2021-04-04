@echo off
chcp 65001
set a=1;
set d=%date:~0,2%-%date:~3,2%-20%date:~6,4%
set t=%time:~0,2%:%time:~3,2%:%time:~6,2%
set t=%t: =%
if not exist ".git" ( git init )
if not exist "README.md" ( echo "# C_SDL" >> README.md )
if %a%==0 (
    git config --global user.email "js201910271836@outlook.com"
    git config --global user.name "js"
    git remote add origin https://github.com/js202005082300/C_SDL.git
    git branch -M main
    git pull https://github.com/js202005082300/C_SDL.git
    git add *
    git commit -a -m "mise-à-jour: %d% %t%"
    git push -u origin main
) else ( 
    git pull https://github.com/js202005082300/C_SDL.git
    git add *
    git commit -a -m "mise-à-jour: %d% %t%"
    git push https://github.com/js202005082300/C_SDL.git
)
exit