/*
All documentation comments are kept in this document
*/
void clear(){} //This is kept in the different documents for compatibility with JS
void info_map()
{
  import std.stdio;
  writeln("H - Help");
  writeln("W - North");
  writeln("A - West");
  writeln("S - South");
  writeln("D - East");
  writeln("Q - Up");
  writeln("Z - Down");
  writeln("M - Medkit");
}
void info_battle()
{
  import std.stdio;
  writeln("B-Big Slash: 15-50 + `pow` damage, 25% chance of missing");
  writeln("Q-Quick Slash: 5-12 + `pow` damage, 10% chance of missing");
  writeln("D-Dodge: 75% chance of dodging all damage");
  writeln("M-Medkit: Restores you to full health");
  writeln("H-Help: Display this help message");
}
