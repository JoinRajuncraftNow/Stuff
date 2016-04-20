var IS_READY=false;
function write(arg)
{
  document.getElementById("ui").innerHTML+=arg;
}
function writeln(arg)
{
  write(arg+"<br></br>");
}
function readln()
{
  while(true)
  {
    if(IS_READY)
    {
      IS_READY=false;
      return document.getElementById("input").value;
    }
    setTimeout(function(){},250);
  }
}
