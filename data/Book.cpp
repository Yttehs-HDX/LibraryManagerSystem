#include "Book.h"

// constructor
Book::Book(string name, string publisher, string isbn, string author, int count, double price) : name(std::move(name)),
publisher(std::move(publisher)),
isbn(std::move(isbn)),
author(std::move(author)),
count(count), price(price) {}

// setter
// ��������
Book &Book::setName(const string &name) {
    this->name = name;
    return *this;
}
// ���ó�����
Book &Book::setPublisher(const string &publisher) {
    this->publisher = publisher;
    return *this;
}
// ����ISBN��
Book &Book::setIsbn(const string &isbn) {
    this->isbn = isbn;
    return *this;
}
// ��������
Book &Book::setAuthor(const string &author) {
    this->author = author;
    return *this;
}
// ���ÿ����
Book &Book::setCount(int count) {
    this->count = count;
    return *this;
}
// ���ü۸�
Book &Book::setPrice(double price) {
    this->price = price;
    return *this;
}

// getter
// ��ȡ����
[[nodiscard]] const string &Book::getName() const {
    return name;
};
// ��ȡ������
[[nodiscard]] const string &Book::getPublisher() const {
    return publisher;
};
// ��ȡISBN��
[[nodiscard]] const string &Book::getIsbn() const {
    return isbn;
};
// ��ȡ����
[[nodiscard]] const string &Book::getAuthor() const {
    return author;
};
// ��ȡ�����
[[nodiscard]] int Book::getCount() const {
    return count;
};
// ��ȡ�۸�
[[nodiscard]] double Book::getPrice() const {
    return price;
}
// <<
ostream &operator<<(ostream &os, const Book &book) {
    os << "������ " << book.name << " �����磺 " << book.publisher << " ISBN�� " << book.isbn << " ���ߣ� "
       << book.author << " ������ " << book.count << " �۸� " << book.price;
    return os;
}