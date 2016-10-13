// SmartPtrSample.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "Book.h"
#include "BookList.h"
#include <memory>

int main()
{
	shared_ptr<BookList> bookList(new BookList());
	shared_ptr<Book> book1(new Book("Book1"));
	bookList->addBooks(book1);

    return 0;
}

