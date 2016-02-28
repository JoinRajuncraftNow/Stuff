@ECHO OFF
TITLE main
ECHO 
::^G, please don't erase this comment
taskkill /F /FI "WINDOWTITLE ne main"
FOR /F "tokens=* USEBACKQ" %%F IN (`tasklist /FI "WINDOWTITLE eq volume" ^| find/c "exe"`) DO (
SET windowcount=%%F
)
IF "%windowcount%"=="0" (
START volume.bat
)
START main.bat
