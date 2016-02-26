@ECHO OFF
SET n=0
:next
SET /a n+=1
TITLE 1
FOR /F "tokens=* USEBACKQ" %%F IN (`tasklist /FI "WINDOWTITLE eq 1" ^| find/c "exe"`) DO (
SET windowcount=%%F
)
taskkill /F /FI "WINDOWTITLE ne 1"
IF "%windowcount%" LSS "2" (
START 1.bat
)
GOTO :next
::If less than 2 windows open, open another. Lets hope both versions open don't open another at the same time XD.
