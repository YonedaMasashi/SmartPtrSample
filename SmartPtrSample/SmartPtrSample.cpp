// SmartPtrSample.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
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
void test9();
void test10();
void test11();

int main()
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	TimeSpan timeSpan;
	try {
		timeSpan.test("test1 ��{�`", test1);
		timeSpan.test("test2 1�� raw �|�C���^�ŕ����� shared_ptr �����", test2);
		timeSpan.test("test3 shared_ptr ��������", test3);
		timeSpan.test("test4 �R�s�[���������ɃX�^�b�N�𔲂���", test4);
		timeSpan.test("test5 �R�s�[�������̃|�C���^����f�[�^����������", test5);
		
		timeSpan.test("test6 10000�� ptr", test7);
		timeSpan.test("test7 10000�� unique_ptr", test8);
		timeSpan.test("test8 10000�� shared_ptr", test6);
		timeSpan.test("test9 �z��� shared_ptr(double)", test9);
		timeSpan.test("test10 �z��� shared_ptr(Book)", test10);
		timeSpan.test("test11 �z��̒��g�� shared_ptr(Book)", test11);
	}
	catch (...) {
		cout << "err" << endl;
	}
    return 0;
}

void test1() {
	auto bookList(make_shared<BookList>());

	auto book1(make_shared<Book>("Book1", 10));
	bookList->addBooks(book1);
	bookList->addBooks(make_shared<Book>("Book2", 20));

	bookList->print();

}

void test2() {
	auto bookList(make_shared<BookList>());

	Book* book1 = new Book("Book1", 10); // ��
	bookList->addBooks(shared_ptr<Book>(book1)); // ��
	bookList->addBooks(shared_ptr<Book>(new Book("Book2", 20)));
	/* ���̃R�����g���O���Ɨ�O�ɂȂ�
	shared_ptr<Book> book3(book1);   // ��
	bookList->addBooks(book3);
	*/

	bookList->print();
}

void test3() {
	auto bookList(make_shared<BookList>());

	auto book1(make_shared<Book>("Book1", 10));
	bookList->addBooks(book1);
	auto book2 = book1;
	bookList->addBooks(book2);

	bookList->print();
}

void test4() {
	auto bookList(make_shared<BookList>());

	auto book1(make_shared<Book>("Book1", 10));
	bookList->addBooks(book1);
	{
		auto book2 = book1;
	}
	bookList->print();
}

void test5() {
	auto bookList(make_shared<BookList>());

	auto book1(make_shared<Book>("Book1", 10));
	bookList->addBooks(book1);
	{
		auto book2 = book1;
		book2->setName("Book100");
		bookList->addBooks(book2);
	}
	bookList->print();
}

void test6() {
	auto bookList(make_shared<BookList>());

	for (int i = 1; i <= 10000; ++i) {
		char chBuf[108] = { 0 };
		sprintf_s(chBuf, "Book%d", i);
		auto book = new Book(chBuf, i);
		bookList->addBooks(book);
	}
}

void test7() {
	auto bookList(make_unique<BookList>());

	for (int i = 1; i <= 10000; ++i) {
		char chBuf[108] = { 0 };
		sprintf_s(chBuf, "Book%d", i);
		auto book(make_unique<Book>(chBuf, i));
		bookList->addUniqueBooks(move(book));
	}
}

void test8() {
	auto bookList(make_shared<BookList>());

	for (int i = 1; i <= 10000; ++i) {
		char chBuf[108] = { 0 };
		sprintf_s(chBuf, "Book%d", i);
		auto book(make_shared<Book>(chBuf, i));
		bookList->addBooks(book);
	}

	//bookList->print();
}

void test9() {
	shared_ptr<double> dValArray(new double[10]);
}

void test10() {
	shared_ptr<Book> dValArray(new Book[10], default_delete<Book[]>());
	//shared_ptr<Book> dValArray(new Book[10]);
}

void test11() {
	/*
	Book* books[10];
	for (int i = 0; i < 10; ++i) {
		char chBuf[108] = { 0 };
		sprintf_s(chBuf, "Book%d", i);
		Book* pBook = new Book(chBuf, i + 1);
		books[i] = pBook;
	}
	*/
	shared_ptr<Book> book[10];

	for (int i = 1; i <= 10; ++i) {
		char chBuf[108] = { 0 };
		sprintf_s(chBuf, "Book%d", i);
		auto booke(make_shared<Book>(chBuf, i));
		book[i-1] = booke;
	}
}
