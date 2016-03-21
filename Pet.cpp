#include <iostream>
#include <string>
#include <ctime>
#include <ifstream>

using namespace std;

int read()
{
	int n;
	ifstream read("data.txt");
	if(read>>n)
	{
		return whattime()-n; //Idk if this will work. Trying to make something that returns current time-data in file. Testing now.
	}
}

lines=i-1;
}
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
