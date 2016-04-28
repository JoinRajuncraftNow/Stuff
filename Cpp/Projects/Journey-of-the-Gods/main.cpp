#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#ifdef _WIN32 || _WIN64
#include <conio.h>
#define KEY_UP 119
#define KEY_DOWN 115
#define KEY_LEFT 97
#define KEY_RIGHT 100
using namespace std;
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
#include <cstdio>
#define KEY_UP 65
#define KEY_LEFT 68
#define KEY_DOWN 66
#define KEY_RIGHT 67
void move()
{
	setvbuf(stdin, NULL, _IONBF, 0);
	int c=0,x=0,y=0,temp1,temp2;
	temp1=getchar();
	temp2=getchar();
	for(;;)
	{
		if(temp1==27&&temp2==91)
		{
			switch(c=getch())
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
}
#endif
int main()
{
   move();
}

