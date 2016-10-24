#include "BookList.h"

#include <algorithm>
#include "Book.h"

BookList::BookList()
{
}


BookList::~BookList()
{
	for (auto book : cntBookNews) {
		delete book;
	}
}

void BookList::addBooks(shared_ptr<Book> book)
{
	cntBooks.push_back(book);
}

void BookList::addUniqueBooks(unique_ptr<Book> book)
{
	cntUniqBooks.push_back(move(book));
}

void BookList::addBooks(Book* book)
{
	cntBookNews.push_back(book);
}

void BookList::print()
{
	for(auto book : cntBooks) {
		book->print();
	}
}
