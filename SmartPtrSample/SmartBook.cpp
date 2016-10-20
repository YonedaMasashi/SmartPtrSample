#include "SmartBook.h"



SmartBook::SmartBook(string name, long lPrice)
{
	m_name = name;
	m_lPrice = lPrice;
}

SmartBook::~SmartBook()
{
}

shared_ptr<SmartBook> SmartBook::create(string name, long lPrice)
{
	return shared_ptr<SmartBook>(new SmartBook(name, lPrice));
}

shared_ptr<SmartBook> SmartBook::setName(string name)
{
	return shared_ptr<SmartBook>(new SmartBook(name, m_lPrice));
}
