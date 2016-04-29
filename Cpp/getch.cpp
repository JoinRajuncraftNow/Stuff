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
  system("read -n 1 c;echo $c>c.txt;echo -e -n '\\b'");
  ifstream i;
  i.open("c.txt");
  char c;
  i >> c;
  i.close();
  return c;
}
#endif
int main()
{
	int u=getch();
	int v=getch();
	int w=getch();
	cout << u << endl << v << endl << w << endl;
}
