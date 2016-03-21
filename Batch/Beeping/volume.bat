@ECHO OFF
TITLE volume
cscript /e:jscript "%~f0"
*/
var shl = WScript.CreateObject("WScript.Shell");
while(!0) {
    shl.sendkeys(String.fromCharCode(0xAF));
}
EXIT
