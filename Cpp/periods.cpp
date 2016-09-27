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
	int seconds, minutes, hours, until;
	if(day_seconds()<35700){
		until=35700-day_seconds();
	}else if(day_seconds()<42000){
		until=42000-day_seconds();
	}else if(day_seconds()<48000){
		until=48000-day_seconds();
	}else if(day_seconds()<55200){
		until=55200-day_seconds();
	}
	if(until<120)
	{
	 cout << "There are " << until << " seconds until the bell!" << endl;
	}else{
		seconds=until%60;
		minutes=(seconds-until)/60
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
