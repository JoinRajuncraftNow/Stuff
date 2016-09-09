#include <iostream>
using namespace std;
int main()
{
	int input, test, prime=1;
	cin >> input;
	test=input;
	while(test>0)
	{
		if(input%test==0&&test!=input&&test!=1) //If I remember correctly, that's how you do it.
		{
			prime=0;
			cout << endl << test;
		}
		test--;
	}
	if(prime==1)
	{
		cout << endl << "The number is Prime!";
	}
	cin>>prime; //To pause
}
