#include <time.h>
#ifdef __linux
#define LINUX
#endif
#ifdef __linux__
#define LINUX
#endif
#ifdef __unix
#define LINUX
#endif
#ifdef __unix__
#define LINUX
#endif
#ifndef LINUX
#include <windows.h>
#endif
#include <stdlib.h>
#include <iostream>
using namespace std;
int day_seconds()
{
	time_t stamp=time(NULL);
	struct tm* diferencia=localtime(&stamp);
	return diferencia->tm_hour*3600+diferencia->tm_min*60+diferencia->tm_sec;
}
int main() 
{
	while(true)
	{
		int seconds, minutes, hours, until, ds;
		ds = day_seconds();
		if(ds<=35700){
			until=35700-ds;
		}else if(ds<=42000){
			until=42000-ds;
		}else if(ds<=48000){
			until=48000-ds;
		}else if(ds<=55200){
			until=55200-ds;
		} else {
			cout << "Wrong time and/or glitch!" << endl;
			return 0;
		}
		if(until<120)
		{
		 cout << "There are " << until << " seconds until the bell!" << endl;
		}else{
			seconds=until%60;
			minutes=(until-seconds)/60;
			if(minutes>60)
			{
				minutes-=60;
				cout << "There is 1 hour, " << minutes << " minutes, and " << seconds << " seconds until the bell!" << endl;
			}else{
				cout << "There are " << minutes << " minutes, and " << seconds << " seconds until the bell!" << endl;
			}
		}
#ifndef LINUX
		Sleep(1000);
#endif
#ifdef LINUX
		system("sleep 1");
#endif
	}
}
/* PERIODS
9:55 - 35,700
11:40 - 42,000
1:20 - 48,000
3:20 - 55,200
*/
