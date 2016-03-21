set _cd=%cd%
for /r %_cd% %%i in (*.txt) do (
  copy %%i TxtFiles\%%i
)
for /r %_cd% %%i in (*.bat) do (
  copy %%i Batch\%%i
)
for /r %_cd% %%i in (*.d) do (
  copy %%i DFiles\%%i
)
