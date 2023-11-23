#ifndef LIBRARYMANAGERSYSTEM_BOOKLIST_H
#define LIBRARYMANAGERSYSTEM_BOOKLIST_H

#include <iostream>
#include <vector>
#include <fstream>
#include "Book.h"

#define FILEPATH "books"

class BookList {
private:
    BookList() {}; // 不可外露构造函数，C++没有静态类只能这样
    static vector<Book> books;
public:
    static void initBooks();
    static void saveAllBooks();
};


#endif //LIBRARYMANAGERSYSTEM_BOOKLIST_H
