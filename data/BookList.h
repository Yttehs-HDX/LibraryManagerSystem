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
    // 存储所有书本
    vector<Book> books {Book("123456789", "123456789", "123456789", "1", 0, 0)};
    // 打印信息
    void printOneBook(const Book &book);
    void printBooks();

    // 查找，返回指针或vector
    vector<Book> searchBooksByName(const string &name);
    Book * searchBookByIsbn(const string &isbn);
    vector<Book> searchBooksByAuthor(const string &author);
    vector<Book> searchBooksByPublisher(const string &publisher);

    // 修改
    void modifyBooks(vector<Book> &buffer);
    void modifyOneBook(Book *book);
public:
    // 读出信息：从文件中将图书信息读入程序
    void initBooks();

    // 图书存盘：将当前程序中的图书信息存入文件中
    void saveAllBooks();

    // 统计功能：输出当前书库中所有图书的总数及详细信息
    void showAllBooksByPrice();
    void showAllBooksByCount();
    void showAllBooksByAuthor();
    void showAllBooksByPublisher();

    // 查询功能：可按书名、ISBN号、作者、出版社进行查询
    void findBooksByName(const string &name);
    void findBookByIsbn(const string &isbn);
    void findBooksByAuthor(const string &author);
    void findBooksByPublisher(const string &publisher);

    // 修改功能：可根据查询结果对相应的记录进行修改
    void modifyBooksByName(const string &name);
    void modifyBooksByIsbn(const string &isbn);
    void modifyBooksByAuthor(const string &author);
    void modifyBooksByPublisher(const string &publisher);

    // 删除功能：主要完成图书信息的删除
    void deleteBook(const string &isbn);

    // 销售功能
    void sellBook(const string &isbn);

    // 添加功能：主要完成图书信息的添加，要求ISBN号唯一
    void addBook(const string &isbn);
};

#endif //LIBRARYMANAGERSYSTEM_BOOKLIST_H
