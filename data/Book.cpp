#include "Book.h"

// constructor
Book::Book(string name, string publisher, string isbn, string author, int count, double price) : name(std::move(name)),
publisher(std::move(publisher)),
isbn(std::move(isbn)),
author(std::move(author)),
count(count), price(price) {}

// setter
// 设置书名
Book &Book::setName(const string &name) {
    this->name = name;
    return *this;
}
// 设置出版社
Book &Book::setPublisher(const string &publisher) {
    this->publisher = publisher;
    return *this;
}
// 设置ISBN号
Book &Book::setIsbn(const string &isbn) {
    this->isbn = isbn;
    return *this;
}
// 设置作者
Book &Book::setAuthor(const string &author) {
    this->author = author;
    return *this;
}
// 设置库存量
Book &Book::setCount(int count) {
    this->count = count;
    return *this;
}
// 设置价格
Book &Book::setPrice(double price) {
    this->price = price;
    return *this;
}

// getter
// 获取书名
[[nodiscard]] const string &Book::getName() const {
    return name;
};
// 获取出版社
[[nodiscard]] const string &Book::getPublisher() const {
    return publisher;
};
// 获取ISBN号
[[nodiscard]] const string &Book::getIsbn() const {
    return isbn;
};
// 获取作者
[[nodiscard]] const string &Book::getAuthor() const {
    return author;
};
// 获取库存量
[[nodiscard]] int Book::getCount() const {
    return count;
};
// 获取价格
[[nodiscard]] double Book::getPrice() const {
    return price;
}