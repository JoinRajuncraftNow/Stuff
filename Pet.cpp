#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

int whattime()
{
	time_t t=time(0);
	return t;
}

int read()
{
	int n, t=whattime();
	ifstream read("data.txt");
	if(read>>n)
	{
		return t-n; //Idk if this will work. Trying to make something that returns current time-data in file. Testing now.
	}
}
/*
This program is meant to be an interactive pet that keeps track of time with text files. Huge WIP, finish later.
*/

int main()
{
	int health=1000, sick=0, hunger=0;
	while(true)
	{
		cout << read() << endl;
	}
}
