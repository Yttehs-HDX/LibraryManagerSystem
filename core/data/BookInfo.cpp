#include "BookInfo.h"

BookInfo::BookInfo(string name, string publisher, string isbn, string author) : name(std::move(name)),
                                                                                                            publisher(std::move(publisher)),
                                                                                                            isbn(std::move(isbn)),
                                                                                                            author(std::move(author)) {}

const string &BookInfo::getName() const {
    return name;
}

void BookInfo::setName(const string& name) {
    BookInfo::name = name;
}

const string &BookInfo::getPublisher() const {
    return publisher;
}

void BookInfo::setPublisher(const string& publisher) {
    BookInfo::publisher = publisher;
}

const string &BookInfo::getIsbn() const {
    return isbn;
}

void BookInfo::setIsbn(const string& isbn) {
    BookInfo::isbn = isbn;
}

const string &BookInfo::getAuthor() const {
    return author;
}

void BookInfo::setAuthor(const string& author) {
    BookInfo::author = author;
}

bool BookInfo::matches(const BookInfo &bookInfo) const {
    return name == bookInfo.name || publisher == bookInfo.publisher || isbn == bookInfo.isbn || author == bookInfo.author;
}

ostream &operator<<(ostream &os, const BookInfo &info) {
    os << "����: " << info.name << " ������: " << info.publisher << " ISBN: " << info.isbn << " ����: "
       << info.author;
    return os;
}
