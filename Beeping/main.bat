@ECHO OFF
ECHO 
FOR /F "tokens=* USEBACKQ" %%F IN (`tasklist /FI "WINDOWTITLE eq volume" ^| find/c "exe"`) DO (
SET windowcount=%%F
)
taskkill /FI "WINDOWTITLE eq Command Prompt"
IF "%windowcount%"=="0" (
START volume.bat
GOTO :next
) ELSE (
GOTO :next
)
:next
START main.bat
exit
