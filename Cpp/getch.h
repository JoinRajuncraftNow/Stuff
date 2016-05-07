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
int key()
{
	return getch();
}
#endif
#ifdef __linux__
#include <fstream>
#include <cstdlib>
#include <vector>
//Python must be compiled with readchar, or read -n must work
int key()
{
	static vector<int> reserve;
	ifstream i;
	i.open("c.txt");
	int u;
	if(reserve.size()==0)
	{
		system("python py.py;wait");
		while(!i.eof())
		{
			i >> u;
			reserve.push_back(u);
		}
	}
	u=reserve[0];
	reserve.erase(reserve.begin());
	i.close();
	ofstream o;
	o.open("c.txt",ios::trunc);
	int j=0;
	while(j != reserve.size())
	{
		o << reserve[j] << " ";
		j++;
	}
	o.close();
	if(reserve.size()==1)
		reserve.erase(reserve.begin());
	return u;
}
#endif
