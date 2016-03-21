#include <iostream>
#include <string>
#include <ctime>

using namespace std;

/*
This program is meant to be an interactive pet that keeps track of time with text files. Huge WIP, finish later.
*/

int whattime()
{
	time_t t=time(0);
	return t;
}

int main()
{
	int health=1000, sick=0, hunger=0;
	while(true)
	{
		cout << whattime() << endl;
	}
}
