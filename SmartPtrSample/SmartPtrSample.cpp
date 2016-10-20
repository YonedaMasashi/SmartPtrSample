// SmartPtrSample.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "Book.h"
#include "BookList.h"
#include <memory>

#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h> 
#include <crtdbg.h>

void test1();
void test2();
void test3();
void test4();
void test5();

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	try {
		test1();
		test2();
		test3();
		test4();
		test5();
	}
	catch (...) {
		cout << "err" << endl;
	}
    return 0;
}

void test1() {
	cout << "test1 基本形" << endl;
	auto bookList(make_shared<BookList>());

	auto book1(make_shared<Book>("Book1"));
	bookList->addBooks(book1);
	bookList->addBooks(make_shared<Book>("Book2"));

	bookList->print();
	cout << "----------------------------------" << endl;

}

void test2() {
	cout << "test2 1つの raw ポインタで複数の shared_ptr を作る" << endl;
	auto bookList(make_shared<BookList>());

	Book* book1 = new Book("Book1"); // ★
	bookList->addBooks(shared_ptr<Book>(book1)); // ★
	bookList->addBooks(shared_ptr<Book>(new Book("Book2")));
	/* このコメントを外すと例外になる
	shared_ptr<Book> book3(book1);   // ★
	bookList->addBooks(book3);
	*/

	bookList->print();
	cout << "----------------------------------" << endl;
}

void test3() {
	cout << "test3 shared_ptr を代入する" << endl;
	auto bookList(make_shared<BookList>());

	auto book1(make_shared<Book>("Book1"));
	bookList->addBooks(book1);
	auto book2 = book1;
	bookList->addBooks(book2);

	bookList->print();
	cout << "----------------------------------" << endl;
}

void test4() {
	cout << "test4 コピーした方を先にスタックを抜ける" << endl;
	auto bookList(make_shared<BookList>());

	auto book1(make_shared<Book>("Book1"));
	bookList->addBooks(book1);
	{
		auto book2 = book1;
	}
	bookList->print();
	cout << "----------------------------------" << endl;
}

void test5() {
	cout << "test5 コピーした方のポインタからデータを書き換え" << endl;
	auto bookList(make_shared<BookList>());

	auto book1(make_shared<Book>("Book1"));
	bookList->addBooks(book1);
	{
		auto book2 = book1;
		book2->setName("Book100");
	}
	bookList->print();
	cout << "----------------------------------" << endl;
}
