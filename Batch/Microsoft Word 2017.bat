::One of the first batch files I made.
@ECHO OFF
SET /P titl=Title: 
:newline
SET /P text=Text: 
ECHO %text% >>"%titl%.txt"
ECHO Line Saved!
GOTO :newline
