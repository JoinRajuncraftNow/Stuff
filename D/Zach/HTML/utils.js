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
function clear() //Only used in HTML, so it won't look awful
{
  document.getElementById("ui").innerHTML="";
}
