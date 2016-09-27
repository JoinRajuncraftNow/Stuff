#include <time.h>
#include <stdio.h>

time_t
day_seconds() 
{
	time_t t1, t2;
	struct tm tms;
	time(&t1);
	localtime_r(&t1, &tms);
	tms.tm_hour = 0;
	tms.tm_min = 0;
	tms.tm_sec = 0;
	t2 = mktime(&tms);
	return t1 - t2;
}

int
main() 
{
	cin.ignore(10000,'\n');
	cout << day_seconds();
	if(day_seconds()<35700){
		cout << "There are " << 35700-day_seconds() << " seconds until 2nd period!" << endl;
	}else if(day_seconds()<42000){
		cout << "There are " << 42000-day_seconds() << " seconds until 2nd period!" << endl;
	}else if(day_seconds()<48000){
		cout << "There are " << 48000-day_seconds() << " seconds until 2nd period!" << endl;
	}else if(day_seconds()<55200){
		cout << "There are " << 55200-day_seconds() << " seconds until 2nd period!" << endl;//I will do conversions later, just testing now.
	}
	return 0;
}
/* PERIODS
9:55 - 35,700
11:40 - 42,000
1:20 - 48,000
3:20 - 55,200
*/
