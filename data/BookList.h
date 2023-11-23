#ifndef LIBRARYMANAGERSYSTEM_BOOKLIST_H
#define LIBRARYMANAGERSYSTEM_BOOKLIST_H

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Book.h"

#define FILEPATH "books"

class BookList {
private:
    BookList() {}; // 不可外露构造函数，C++没有静态类只能这样

    // 存储所有书本
    static vector<Book> books;

    static void printBooks();
public:
    // 读出信息：从文件中将图书信息读入程序
    static void initBooks();

    // 图书存盘：将当前程序中的图书信息存入文件中
    static void saveAllBooks();

    // 统计功能：输出当前书库中所有图书的总数及详细信息
    static void showAllBooksByPrice();
    static void showAllBooksByCount();
    static void showAllBooksByAuthor();
    static void showAllBooksByPublisher();

    // 销售功能
    static void sellBook(const string &isbn);
};


#endif //LIBRARYMANAGERSYSTEM_BOOKLIST_H
