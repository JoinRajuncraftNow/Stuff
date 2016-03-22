#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

int read()
{
	int n, t=time(0); //Will this work?
	ifstream in("data.txt");
	in >> n;
	return t-n;
}

void output()
{
	int t=time(0);
	ifstream out("data.txt")
	out << t;
}

int main()
{
	int health=1000, sick=0, hunger=0;
	while(true)
	{
		cout << read() << endl;
	}
}
