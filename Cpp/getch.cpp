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
int getch_()
{
	return getch();
}
#endif
#ifdef __linux__
#include <fstream>
#include <ncurses.h>
//Must be compiled with lncurses option
int getch_()
{
    WINDOW* scr = initscr();
    wresize(scr,0,0)
    int t = getch();
    endwin();
    cout << t << endl;
}
#endif

#include <iostream>
int main()
{
	int u;
	for(;;){u=getch();cout << u << endl;}
}
