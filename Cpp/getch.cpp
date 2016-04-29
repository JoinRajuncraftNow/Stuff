#ifdef _WIN32
#define _WIN64
#endif
#ifdef __unix
#define __linux__
#endif
#ifdef __unix__
#define __linux__
#endif
using namespace std;
#ifdef _WIN64
#include <conio.h>
#endif
#ifdef __linux__
#include <iostream>
#include <cstdlib>
int getch()
{
  system("read -n 1 c;echo $c>c.txt");
  istream i;
  i.open("c.txt");
  char c;
  i >> c;
  i.close();
  return c;
}
