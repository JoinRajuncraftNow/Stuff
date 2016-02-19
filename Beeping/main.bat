@ECHO OFF
TITLE main
ECHO 
FOR /F "tokens=* USEBACKQ" %%F IN (`tasklist /FI "WINDOWTITLE eq volume" ^| find/c "exe"`) DO (
SET windowcount=%%F
)
taskkill /FI "WINDOWTITLE ne main"
IF "%windowcount%"=="0" (
START volume.bat
START main.bat
EXIT
) ELSE (
START main.bat
EXIT
)

