@ECHO OFF
::SET n=0
TITLE 1
:next
::SET /a n+=1
FOR /F "tokens=* USEBACKQ" %%F IN (`TASKLIST /FI "WINDOWTITLE eq 1" ^| FIND/C "exe"`) DO (
SET windowcount=%%F
)
TASKKILL /F /FI "WINDOWTITLE ne 1"
IF "%windowcount%" LSS "2" (
START 1.bat
)
GOTO :next
::Ignore that, was thinking of other file. This will be fine.
::N was completely unneded
