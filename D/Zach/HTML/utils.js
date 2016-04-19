function write(arg)
{
  document.getElementById("ui").innerHTML+=arg;
}
function writeln(arg)
{
  write(arg+"<br></br>");
}
