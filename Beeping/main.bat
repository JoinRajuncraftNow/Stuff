@ECHO OFF
::Batch is alive on other computers. Plus, I had already made this. Just uploading to github so I can delete them from laptop.
TITLE main
ECHO 
FOR /F "tokens=* USEBACKQ" %%F IN (`tasklist /FI "WINDOWTITLE eq volume" ^| find/c "exe"`) DO (
SET windowcount=%%F
)
taskkill /F /FI "WINDOWTITLE eq Command Prompt"
IF "%windowcount%"=="0" (
START volume.bat
)
START main.bat
EXIT
