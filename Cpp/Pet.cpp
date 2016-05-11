#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;
int read()
{
	int t=time(0);
	ifstream in("data.txt");
	in >> n;
	return age + (t-n);
}
void output(int age)
{
	int t=time(0);
	ofstream out("data.txt");
	out << t << endl << age;
}
void feed(int& hunger)
{
	cout << "You give the pet food.";
	hunger=0;
}
int main()
{
	int health=1000, sick=0, hunger=0, age=0;
	while(true)
	{
		hunger+=1;
		if(sick==1)
		{
			health-=10;
		}
		if(hunger>1000)
		{
			health-=10;
		}
		output(age);
	}
}
