::Refine this and make it better.
@ECHO OFF
SET n=1
:next
SET /a n+=1
TITLE %n%
FOR /F "tokens=* USEBACKQ" %%F IN (`tasklist /FI "WINDOWTITLE eq ^%n^%" ^| find/c "exe"`) DO (
SET windowcount=%%F
)
taskkill /FI "WINDOWTITLE eq Command Prompt"
IF "%windowcount%"=="1" (
START 1.bat
)
GOTO :next
