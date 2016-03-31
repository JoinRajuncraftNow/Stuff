#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

int read(string file)
{
	int n, t=time(0); //Will this work? Maybe?
	ifstream in(file);
	in >> n;
	return t-n;
}

void output(string file)
{
	int t=time(0);
	ofstream out(file); // Will this work so that I could just check any file with one function?
	out << t;
}

int main()
{
	string file="data.txt";
	int health=1000, sick=0, hunger=0, age=0;
	while(true)
	{
		cout << read(file) << endl;
	}
}
