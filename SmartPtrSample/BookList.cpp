#include "BookList.h"

#include <algorithm>
#include "Book.h"

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
		book->print();
	}
}
