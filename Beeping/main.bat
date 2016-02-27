@ECHO OFF
TITLE main
ECHO 
taskkill /F /FI "WINDOWTITLE ne main"
FOR /F "tokens=* USEBACKQ" %%F IN (`tasklist /FI "WINDOWTITLE eq volume" ^| find/c "exe"`) DO (
SET windowcount=%%F
)
IF "%windowcount%"=="0" (
START volume.bat
)
START main.bat
::Will that work, or will it slow it down too much?
::What
