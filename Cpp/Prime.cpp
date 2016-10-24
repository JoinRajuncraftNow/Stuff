#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int input, test, prime=1;
	cin >> input;
	test=input;
	input=ceil(sqrt(input));
	while(test>0)
	{
		if(input%test==0&&test!=input&&test!=1) 
		{
			prime=0;
		}
		test--;
	}
	return prime;
}
