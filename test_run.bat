@echo off

set /a cas = 1

:again
gen
A < in > a.out
bf < in > bf.out
fc a.out bf.out > nul
if not errorlevel 1 (
	set /a cas += 1
	@echo #%cas% ok 
	@echo.
	goto again 
) else (
	@echo #%cas% wa
)
