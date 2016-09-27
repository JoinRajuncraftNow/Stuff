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
	return 0;
}
