#ifndef LIBRARYMANAGERSYSTEM_BOOK_H
#define LIBRARYMANAGERSYSTEM_BOOK_H

#include <iostream>

using namespace std;

class Book {
private:
    string name{}; // 书名
    string publisher{}; // 出版社
    string isbn{}; // ISBN号
    string author{}; // 作者
    int count{}; // 库存量
    double price{}; // 价格
public:
    // constructor
    Book(string name, string publisher, string isbn, string author, int count, double price);

    // setter
    // 设置书名
    Book &setName(const string &name);
    // 设置出版社
    Book &setPublisher(const string &publisher);
    // 设置ISBN号
    Book &setIsbn(const string &isbn);
    // 设置作者
    Book &setAuthor(const string &author);
    // 设置库存量
    Book &setCount(int count);
    // 设置价格
    Book &setPrice(double price);

    // getter
    // 获取书名
    [[nodiscard]] const string &getName() const;
    // 获取出版社
    [[nodiscard]] const string &getPublisher() const;
    // 获取ISBN号
    [[nodiscard]] const string &getIsbn() const;
    // 获取作者
    [[nodiscard]] const string &getAuthor() const;
    // 获取库存量
    [[nodiscard]] int getCount() const;
    // 获取价格
    [[nodiscard]] double getPrice() const;
};

#endif //LIBRARYMANAGERSYSTEM_BOOK_H