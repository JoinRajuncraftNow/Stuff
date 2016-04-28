#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
#ifdef _WIN32
#define _WIN64
#endif
#ifdef __unix__
#define __linux__
#endif
#ifdef __unix
#define __linux__
#endif
#ifdef _WIN64
#include <conio.h>
#define KEY_UP 119
#define KEY_DOWN 115
#define KEY_LEFT 97
#define KEY_RIGHT 100
void move() //Just a test. DON'T MESS WITH THIS
{
	int c=0, x=0, y=0;
	for(;;)
	{ //OK, since WINDOWS IS STUPID
		switch(c=getch()) //That was annoying me to death figuratively
		{
		case KEY_UP:
			x++;    //key up
			break;
		case KEY_DOWN:
			x--;   // key down
			break;
		case KEY_LEFT:
			y++;  // key left
			break;
		case KEY_RIGHT:
			y--;  // key right
			break;
		default:
			cout << endl << "null" << endl;  // not arrow, OR IT IS THE BEGINNING YOU IDIOT
			break;
		}
	}
}
#elif __linux__ || __unix || __unix

void move()
{
	setvbuf(stdin, NULL, _IONBF, 0);
	int x=0,y=0;
	string c;
	for(;;)
	{
		if(temp1==27&&temp2==91)
		{
			switch(c=cin.getline())
			{
			case "w":
			case "W":
				x++;    //key up
				break;
			case "s":
			case "S":
				x--;   // key down
				break;
			case "a":
			case "A":
				y++;  // key left
				break;
			case "d":
			case "D":
				y--;  // key right
				break;
			default:
				cout << endl << "null" << endl;  // not arrow, OR IT IS THE BEGINNING YOU IDIOT
				break;
			}
		}
	}
}
#endif
int main()
{
  	move();
}

