#include "TimeSpan.h"

#include <iostream>

using namespace std;

TimeSpan::TimeSpan()
{
}


TimeSpan::~TimeSpan()
{
}

void TimeSpan::test(string strLog, function<void(void)> func)
{
	clock_t start;
	clock_t end;
	cout << strLog.c_str() << endl;
	start = clock();
	func();
	end = clock();
	cout << "   ˆ—ŽžŠÔ:" << end - start << "[ms]" << endl;
	cout << "-------------------------------------------------------------------" << endl;
}
