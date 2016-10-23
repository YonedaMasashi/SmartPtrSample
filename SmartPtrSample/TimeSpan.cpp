#include "TimeSpan.h"

#include <iostream>

using namespace std;

TimeSpan::TimeSpan()
{
	start = clock();
}


TimeSpan::~TimeSpan()
{
	end = clock();
	cout << "ˆ—ŽžŠÔ:" << end - start << "[ms]" << endl;
}
