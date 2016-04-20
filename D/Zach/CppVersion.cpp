#include <iostream>
using namespace std;
void clear(){}
void info_map()
{
  cout << "H - Help" << endl;
  cout << "W - North" << endl;
  cout << "A - West" << endl;
  cout << "S - South" << endl;
  cout << "D - East" << endl;
  cout << "Q - Up" << endl;
  cout << "Z - Down" << endl;
  cout << "M - Medkit" << endl;
}
void info_battle()
{
  cout << "B-Big Slash: 15-50 + `pow` damage, 25% chance of missing" << endl;
  cout << "Q-Quick Slash: 5-12 + `pow` damage, 10% chance of missing" << endl;
  cout << "D-Dodge: 75% chance of dodging all damage" << endl;
  cout << "M-Medkit: Restores you to full health" << endl;
  cout << "H-Help: Display this help message" << endl;
}
