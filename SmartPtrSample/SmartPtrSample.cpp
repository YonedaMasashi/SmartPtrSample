// SmartPtrSample.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
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
			// Book* book1 = new Book("Book1"); ← こっちは例外
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

