#pragma once

#include <iostream>
using namespace std;

class Book
{
public:
	Book(string name, long price);
	virtual ~Book();

	void print();

	void setName(string name);
	long getPrice();

private:
	string strName;
	long lPrice;
};

