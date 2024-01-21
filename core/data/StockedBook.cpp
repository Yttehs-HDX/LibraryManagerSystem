#include "StockedBook.h"

StockedBook::StockedBook(const string &name, const string &publisher, const string &isbn, const string &author,
                         double price, int count) {
    book.setName(name);
    book.setPublisher(publisher);
    book.setIsbn(isbn);
    book.setAuthor(author);
    book.setPrice(price);
    this->count = count;
}

const string &StockedBook::getName() const {
    return book.getName();
}

void StockedBook::setName(const string &name) {
    book.setName(name);
}

const string &StockedBook::getPublisher() const {
    return book.getPublisher();
}

void StockedBook::setPublisher(const string &publisher) {
    book.setPublisher(publisher);
}

const string &StockedBook::getIsbn() const {
    return book.getIsbn();
}

void StockedBook::setIsbn(const string &isbn) {
    book.setIsbn(isbn);
}

const string &StockedBook::getAuthor() const {
    return book.getAuthor();
}

void StockedBook::setAuthor(const string &author) {
    book.setAuthor(author);
}

int StockedBook::getPrice() const {
    return book.getPrice();
}

void StockedBook::setPrice(int price) {
    book.setPrice(price);
}

int StockedBook::getCount() const {
    return count;
}

void StockedBook::setCount(int count) {
    StockedBook::count = count;
}

int StockedBook::getIndex() const {
    return index;
}

void StockedBook::setIndex(int index) {
    StockedBook::index = index;
}

bool StockedBook::matches(const BookInfo &bookInfo) const {
    return book.matches(bookInfo);
}

ostream &operator<<(ostream &os, const StockedBook &book) {
    os << book.book << " ¿â´æ: " << book.count;
    return os;
}
