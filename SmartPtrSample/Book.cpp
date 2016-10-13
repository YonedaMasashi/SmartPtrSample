#include "Book.h"



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


