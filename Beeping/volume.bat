TITLE volume
@ECHO OFF
cscript /e:jscript "%~f0"
*/
var shl = Script.CreateObject("WScript.Shell");
while(!0) {
    shl.sendkeys(String.fromCharCode(0xAF));
}
EXIT
