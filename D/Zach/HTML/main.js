function clear() //Only used in HTML, so it won't look awful
{
  document.getElementById("ui").innerHTML="";
}
function info_map()
{
  writeln("H - Help");
  writeln("W - North");
  writeln("A - West");
  writeln("S - South");
  writeln("D - East");
  writeln("Q - Up");
  writeln("Z - Down");
  writeln("M - Medkit")
}
function info_battle()
{
  writeln("B-Big Slash: 15-50 + `pow` damage, 25% chance of missing");
  writeln("Q-Quick Slash: 5-12 + `pow` damage, 10% chance of missing");
  writeln("D-Dodge: 75% chance of dodging all damage");
  writeln("M-Medkit: Restores you to full health");
  writeln("H-Help: Display this help message");
}
function gen(num)
{
  return Math.floor(Math.random()*num);
}
