#include <iostream>
using namespace std;
int main()
{
	int input, test, prime=1;
	int inputt, testt, primet=1;
	cin >> input;
	test=input;
	while(test>0)
	{
		if(input%test==0&&test!=input&&test!=1) 
		{
			primet=0;
			inputt=test;
			while(testt>0)
			{
				if(inputt%testt==0&&testt!=inputt&&testt!=1)
				{
					primet=0;
				}
				testt--;
			}
			if(primet==1)
			{
				cout << endl << test;
			}
		}
		cin>>prime; //To pause
		test--;
	}
	if(prime==1)
	{
		cout << endl << "The number is Prime!";
	}
	cin>>prime; //To pause
}
