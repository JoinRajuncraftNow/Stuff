@echo off
if not exist data.txt type nul > data.txt
:loop
set /p NAME=[NAME]
echo.
set /p EMAIL=[EMAIL]
echo.
set /p AGE=[AGE]
echo.
echo ############################################################### >> data.txt
echo [NAME] - %NAME% >> data.txt
echo [EMAIL] - %EMAIL% >> data.txt
echo [AGE] - %AGE% >> data.txt
echo [DATE] - %DATE% >> data.txt
echo [TIME] - %TIME% >> data.txt
echo ############################################################### >> data.txt
echo. >> data.txt
echo. >> data.txt
echo. >> data.txt
echo. >> data.txt
goto :loop
