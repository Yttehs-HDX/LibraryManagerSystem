#ifndef LIBRARYMANAGERSYSTEM_MANAGER_H
#define LIBRARYMANAGERSYSTEM_MANAGER_H

#include "data/StockedBook.h"
#include <list>

#define FILEPATH "stocked_books.txt"

using namespace std;

class Manager {
    Manager() {}

    list<StockedBook> stockedBooks;
public:
    // 单例模式
    Manager(const Manager &) = delete;
    Manager(const Manager &&) = delete;
    Manager operator==(const Manager &) = delete;
    Manager operator==(const Manager &&) = delete;
    static Manager &getInstance();

    // 查找
    list<int> findBookIndexes(const BookInfo& matcher);
    StockedBook &getBookByIndex(int index);
    // 增加
    bool addBook(StockedBook newStockedBook);
    // 删除
    void removeBook(int index);
    // 修改
    void modifyBook(int index, const StockedBook &newStockedBook);
    // 销售
    void saleBook(int index);
    // 获取所有书本
    list<StockedBook> getAllBooks();

    // 读取文件
    void readFile();
    // 写入文件
    void writeFile();
};


#endif //LIBRARYMANAGERSYSTEM_MANAGER_H
