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
    // 打印信息
    static void printOneBook(const Book &book);
    static void printBooks();

    // 查找，返回指针或vector
    static vector<Book> searchBooksByName(const string &name);
    static Book * searchBookByIsbn(const string &isbn);
    static vector<Book> searchBooksByAuthor(const string &author);
    static vector<Book> searchBooksByPublisher(const string &publisher);
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

    // 查询功能：可按书名、ISBN号、作者、出版社进行查询
    static void findBooksByName(const string &name);
    static void findBookByIsbn(const string &isbn);
    static void findBooksByAuthor(const string &author);
    static void findBooksByPublisher(const string &publisher);

    // 销售功能
    static void sellBook(const string &isbn);

    // 添加功能：主要完成图书信息的添加，要求ISBN号唯一
    static void addBook(const string &name, const string &publisher, const string &isbn, const string &author, int count, double price);
};


#endif //LIBRARYMANAGERSYSTEM_BOOKLIST_H
