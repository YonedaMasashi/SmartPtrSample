#pragma once

#include <iostream>
using namespace std;

class Book
{
public:
	Book(string name);
	virtual ~Book();

	void print();

	void setName(string name);

private:
	string strName;
};

