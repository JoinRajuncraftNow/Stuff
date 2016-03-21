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
	ifstream in("data.txt");
	in >> n;
	return t-n;
}

int main()
{
	int health=1000, sick=0, hunger=0;
	while(true)
	{
		cout << read() << endl;
	}
