@set errorlevel=
@C:\gnuwin32\bin\make.EXE sdl > nul

@REM error level = %errorlevel%
@if "%errorlevel%"=="0" GOTO done2
@if "%errorlevel%"=="2" GOTO done1

:done1
@pause > nul

:done2
@REM