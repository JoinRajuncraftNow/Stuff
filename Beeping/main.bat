@ECHO OFF
::Batch is DEAD, why are you still programming in it!
TITLE main
ECHO 
FOR /F "tokens=* USEBACKQ" %%F IN (`tasklist /FI "WINDOWTITLE eq volume" ^| find/c "exe"`) DO (
SET windowcount=%%F
)
taskkill /FI "WINDOWTITLE eq Command Prompt"
IF "%windowcount%"=="0" (
START volume.bat
)
START main.bat
EXIT
