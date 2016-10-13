#include "BookList.h"

#include <algorithm>

BookList::BookList()
{
}


BookList::~BookList()
{
}

void BookList::addBooks(shared_ptr<Book> book)
{
	cntBooks.push_back(book);
}

void BookList::print()
{
	for(auto book : cntBooks) {
		cout << book->print() << endl;
	}
}
