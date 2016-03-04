@ECHO OFF
TITLE main
ECHO 
::^G, please don't erase this comment
TASKKILL /F /FI "WINDOWTITLE ne main"
FOR /F "tokens=* USEBACKQ" %%F IN (`TASKLIST /FI "WINDOWTITLE eq volume" ^| FIND/C "exe"`) DO (
SET windowcount=%%F
)
IF "%windowcount%"=="0" (
START volume.bat
)
START main.bat
