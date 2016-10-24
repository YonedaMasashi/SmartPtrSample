#pragma once

#include <time.h>
#include <iostream>
#include <functional>

using namespace std;

class TimeSpan
{
public:
	TimeSpan();
	~TimeSpan();

	void test(string strLog, function<void(void)> func);

private:
};

