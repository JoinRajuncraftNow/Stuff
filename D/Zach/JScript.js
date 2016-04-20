function clear(){}
function info_map()
{
  WScript.Echo("H - Help");
  WScript.Echo("W - North");
  WScript.Echo("A - West");
  WScript.Echo("S - South");
  WScript.Echo("D - East");
  WScript.Echo("Q - Up");
  WScript.Echo("Z - Down");
  WScript.Echo("M - Medkit");
}
function info_battle()
{
  WScript.Echo("B-Big Slash: 15-50 + `pow` damage, 25% chance of missing");
  WScript.Echo("Q-Quick Slash: 5-12 + `pow` damage, 10% chance of missing");
  WScript.Echo("D-Dodge: 75% chance of dodging all damage");
  WScript.Echo("M-Medkit: Restores you to full health");
  WScript.Echo("H-Help: Display this help message");
}
