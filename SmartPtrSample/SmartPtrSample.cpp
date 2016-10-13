// SmartPtrSample.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include "Book.h"
#include "BookList.h"
#include <memory>

int main()
{
	try {
		{
			shared_ptr<BookList> bookList(new BookList());
			shared_ptr<Book> book1(new Book("Book1"));
			// Book* book1 = new Book("Book1"); �� �������͗�O
			bookList->addBooks(shared_ptr<Book>(book1));
			bookList->addBooks(shared_ptr<Book>(new Book("Book2")));
			bookList->print();
			shared_ptr<Book> book3(book1);
		}
	}
	catch (...) {
		cout << "err" << endl;
	}
    return 0;
}

