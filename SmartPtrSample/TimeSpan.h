#pragma once

#include <time.h>

class TimeSpan
{
public:
	TimeSpan();
	~TimeSpan();

private:
	clock_t start;
	clock_t end;
};

