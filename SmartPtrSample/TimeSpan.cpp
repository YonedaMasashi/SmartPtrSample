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
	cout << "��������:" << end - start << "[ms]" << endl;
}
