#include "Book.h"

#include <memory>

Book::Book(string name, long price)
{
	strName = name;
	lPrice = price;
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

long Book::getPrice() {
	return lPrice;
}
