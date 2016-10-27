#include <iostream> 
#include <cmath>
using namespace std;
bool testprime(int input) //A simpler and faster prime function than I normally make.
{
 	if(input%2==0){ return false; }
	bool prime=true;
	input=ceil(sqrt(input)); //Square root input, then round up.
	int test=input;
	while(test>0) //Test for every value < input, and see if input is divisible.
	{
		if(input%test==0 && test!=input && test!=1) 
		{
			prime=false;
		}
		test--;
	}
	return prime;
}
int main() //main function
{
	int num;
	cin.clear();
	cin >> num; //User input into integer 'num'
	cout << testprime(num) << endl << endl; //Output result of testprime
	main();
}
