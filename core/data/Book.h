#ifndef LIBRARYMANAGERSYSTEM_BOOK_H
#define LIBRARYMANAGERSYSTEM_BOOK_H

#include "BookInfo.h"

using namespace std;

class Book {
    BookInfo info;
    double price{};
public:
    Book() = default;
    Book(const string& name, const string& publisher, const string& isbn, const string& author, double price);

    // getter & setter
    [[nodiscard]] const string &getName() const;
    void setName(const string &name);
    [[nodiscard]] const string &getPublisher() const;
    void setPublisher(const string &publisher);
    [[nodiscard]] const string &getIsbn() const;
    void setIsbn(const string &isbn);
    [[nodiscard]] const string &getAuthor() const;
    void setAuthor(const string &author);
    [[nodiscard]] double getPrice() const;
    void setPrice(double price);

    bool matches(const BookInfo& matcher) const;

    friend ostream &operator<<(ostream &os, const Book &book);
};

#endif //LIBRARYMANAGERSYSTEM_BOOK_H