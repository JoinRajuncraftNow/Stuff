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
#include <fstream>
#include <cstdlib>
int getch()
{
  //system("read -n 1 c;echo $c>c.txt;echo -e -n '\\b'");
  system("echo 'read -n 1 c <&0;echo $c>c.txt;echo -e -n \"\\\\b\"' | /bin/bash")
  ifstream i;
  i.open("c.txt");
  char c;
  i >> c;
  i.close();
  return c;
}
#endif

#include <iostream>
int main()
{
	int u;
	for(;;){u=getch();cout << u << endl;}
}
