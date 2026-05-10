@echo off
g++ main.cpp core/*.cpp ui/*.cpp utils/*.cpp -o LetterCards.exe

if %errorlevel% neq 0 (
    echo Compilation Failed.
    pause
    exit /b 1
)

echo Compilation Completed.
echo.
set /p run="Do you want to run the game? (y/n): "

if /i "%run%"=="y" (
    echo Running the Game...
    LetterCards.exe
) else (
    echo Exiting...
)
