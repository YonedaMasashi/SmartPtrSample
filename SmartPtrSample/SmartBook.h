#pragma once

#include <iostream>
#include <memory>
using namespace std;

class SmartBook
{
public:
	virtual ~SmartBook();

	static shared_ptr<SmartBook> create(string name, long lPrice);

	shared_ptr<SmartBook> setName(string name);

private:
	SmartBook(string name, long lPrice);

private:
	string m_name;
	long m_lPrice;
};

