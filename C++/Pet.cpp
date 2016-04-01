#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

int read(string file)
{
	int n, t=time(0);
	ifstream in("data.txt");
	in >> n;
	return t-n;
}

void output(string file)
{
	int t=time(0);
	ofstream out("data.txt");
	out << t;
}

int main()
{
	int health=1000, sick=0, hunger=0, age=0;
	while(true)
	{
		cout << read() << endl;
	}
}
