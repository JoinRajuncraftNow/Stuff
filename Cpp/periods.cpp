#include <time.h>
#include <windows.h>
#include <iostream>
using namespace std;
int day_seconds()
{
	time_t stamp=time(NULL);
	struct tm* diferencia=localtime(&stamp);
	return ((diferencia->tm_hour*3600)+(diferencia->tm_min*60)+(diferencia->tm_sec));
}
int main() 
{
	if(day_seconds()<35700){
		cout << "There are " << 35700-day_seconds() << " seconds until 1st period ends!" << endl;
	}else if(day_seconds()<42000){
		cout << "There are " << 42000-day_seconds() << " seconds until 2nd period ends!" << endl;
	}else if(day_seconds()<48000){
		cout << "There are " << 48000-day_seconds() << " seconds until 3rd period ends!" << endl;
	}else if(day_seconds()<55200){
		cout << "There are " << 55200-day_seconds() << " seconds until 4th period ends!" << endl;//I will do conversions later, just testing now.
	}
	cin.ignore(10000,'\n');
	main();
}
/* PERIODS
9:55 - 35,700
11:40 - 42,000
1:20 - 48,000
3:20 - 55,200
*/
