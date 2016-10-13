#pragma once

class Book;

#include <memory>
#include <iostream>
#include <vector>

using namespace std;

class BookList
{
public:
	BookList();
	~BookList();

	void addBooks(shared_ptr<Book> book);
	void print();

private:
	vector<shared_ptr<Book>> cntBooks;

};

