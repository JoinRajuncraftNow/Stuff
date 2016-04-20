/*
All documentation comments are kept in this document
*/
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
  writeln("B-Big slash: 15-50 damage, 25% chance of missing");
  writeln("Q-Quick Slash: 5-12 damage, 10% chance of missing");
  writeln("D-Dodge: 75% chance of dodgin all damage");
  writeln("M-Medkit: Restores you to full health");
}
void clear(){} //This is kept in the different documents for compatibility with JS
