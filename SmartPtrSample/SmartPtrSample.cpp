// SmartPtrSample.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "Book.h"
#include "BookList.h"
#include "TimeSpan.h"
#include <memory>

#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h> 
#include <crtdbg.h>

void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void test8();

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	try {
		test1();
		test2();
		test3();
		test4();
		test5();
		{
			TimeSpan timeSpan;
			test6();
		}
		{
			TimeSpan timeSpan;
			test7();
		}
		/*{
			TimeSpan timeSpan;
			test8();
		}*/
	}
	catch (...) {
		cout << "err" << endl;
	}
    return 0;
}

void test1() {
	cout << "test1 基本形" << endl;
	auto bookList(make_shared<BookList>());

	auto book1(make_shared<Book>("Book1", 10));
	bookList->addBooks(book1);
	bookList->addBooks(make_shared<Book>("Book2", 20));

	bookList->print();
	cout << "----------------------------------" << endl;

}

void test2() {
	cout << "test2 1つの raw ポインタで複数の shared_ptr を作る" << endl;
	auto bookList(make_shared<BookList>());

	Book* book1 = new Book("Book1", 10); // ★
	bookList->addBooks(shared_ptr<Book>(book1)); // ★
	bookList->addBooks(shared_ptr<Book>(new Book("Book2", 20)));
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

	auto book1(make_shared<Book>("Book1", 10));
	bookList->addBooks(book1);
	auto book2 = book1;
	bookList->addBooks(book2);

	bookList->print();
	cout << "----------------------------------" << endl;
}

void test4() {
	cout << "test4 コピーした方を先にスタックを抜ける" << endl;
	auto bookList(make_shared<BookList>());

	auto book1(make_shared<Book>("Book1", 10));
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

	auto book1(make_shared<Book>("Book1", 10));
	bookList->addBooks(book1);
	{
		auto book2 = book1;
		book2->setName("Book100");
		bookList->addBooks(book2);
	}
	bookList->print();
	cout << "----------------------------------" << endl;
}

void test6() {
	cout << "test6 10000回 shared_ptr" << endl;
	auto bookList(make_shared<BookList>());

	for (int i = 1; i <= 10000; ++i) {
		char chBuf[108] = { 0 };
		sprintf_s(chBuf, "Book%d", i);
		auto book(make_shared<Book>(chBuf, i));
		bookList->addBooks(book);
	}

	//bookList->print();
	cout << "----------------------------------" << endl;
}

void test7() {
	cout << "test7 10000回 ptr" << endl;
	auto bookList(make_shared<BookList>());

	for (int i = 1; i <= 10000; ++i) {
		char chBuf[108] = { 0 };
		sprintf_s(chBuf, "Book%d", i);
		auto book = new Book(chBuf, i);
		bookList->addBooks(book);
	}

	cout << "----------------------------------" << endl;
}

void test8() {
	/*
	cout << "test8 10000回 unique_ptr" << endl;
	auto bookList(make_unique<BookList>());

	for (int i = 1; i <= 10000; ++i) {
		char chBuf[108] = { 0 };
		sprintf_s(chBuf, "Book%d", i);
		auto book(make_unique<Book>(chBuf, i));
		bookList->addUniqueBooks(book);
	}

	cout << "----------------------------------" << endl;
	*/
}
