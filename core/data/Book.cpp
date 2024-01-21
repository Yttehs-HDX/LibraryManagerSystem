#include "Book.h"

Book::Book(const string& name, const string& publisher, const string& isbn, const string& author, double price) {
    info.setName(name);
    info.setIsbn(isbn);
    info.setPublisher(publisher);
    info.setAuthor(author);
    this->price = price;
}

const string &Book::getName() const {
    return info.getName();
}

void Book::setName(const string &name) {
    info.setName(name);
}

const string &Book::getPublisher() const {
    return info.getPublisher();
}

void Book::setPublisher(const string &publisher) {
    info.setPublisher(publisher);
}

const string &Book::getIsbn() const {
    return info.getIsbn();
}

void Book::setIsbn(const string &isbn) {
    info.setIsbn(isbn);
}

const string &Book::getAuthor() const {
    return info.getAuthor();
}

void Book::setAuthor(const string &author) {
    info.setAuthor(author);
}

double Book::getPrice() const {
    return price;
}

void Book::setPrice(double price) {
    Book::price = price;
}

bool Book::matches(const BookInfo &matcher) const{
    return info.matches(matcher);
}

ostream &operator<<(ostream &os, const Book &book) {
    os << book.info << " ¼Û¸ñ: " << book.price;
    return os;
}
