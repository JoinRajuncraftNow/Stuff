::Please, create a backup!
@echo off
color 0a
::MATRIX
set _cd=%cd%
set pd=%cd%\..
for /r %_cd% %%i in (*.txt) do (
  copy %%i %pd%\TxtFiles\%%i
)
for /r %_cd% %%i in (*.bat) do (
  copy %%i %pd%\BatchFiles\%%i
)
for /r %_cd% %%i in (*.d) do (
  copy %%i %pd%\DFiles\%%i
)
for /r %_cd% %%i in (*.cpp) do (
  copy %%i %pd%\CppFiles\%%i
)
del *.d
del *.cpp
del *.bat
del *.txt
xcopy /i %pd%\TxtFiles %_cd%\TxtFiles
xcopy /i %pd%\BatchFiles %_cd%\BatchFiles
xcopy /i %pd%\DFiles %_cd%\DFiles
xcopy /i %pd%\CppFiles %_cd%\CppFiles
del /s %pd%\TxtFiles\*
del /s %pd%\BatchFiles\*
del /s %pd%\DFiles\*
del /s %pd%\CppFiles\*
