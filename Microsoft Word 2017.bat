::One of the first batch files I made.
@ECHO OFF
SET /p titl=Title: 
:newline
SET /p text=Text: 
ECHO %text% >>"%titl%.txt"
ECHO Line Saved!
GOTO :newline
