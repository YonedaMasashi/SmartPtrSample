#include "Book.h"

#include <memory>

Book::Book(string name)
{
	strName = name;
}


Book::~Book()
{
}

void Book::print()
{
	cout << strName.c_str() << endl;
}

void Book::setName(string name)
{
	strName = name;
}


