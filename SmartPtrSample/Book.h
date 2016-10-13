#pragma once

#include <iostream>
using namespace std;

class Book
{
public:
	Book(string name);
	~Book();

	void print();

private:
	string strName;
};

