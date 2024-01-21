#ifndef LIBRARYMANAGERSYSTEM_STOCKEDBOOK_H
#define LIBRARYMANAGERSYSTEM_STOCKEDBOOK_H

#include "Book.h"

using namespace std;

class StockedBook {
    Book book;
    int count{};
    int index{};
public:
    int getIndex() const;

    void setIndex(int index);

public:
    StockedBook() = default;
    StockedBook(const string& name, const string& publisher, const string& isbn, const string& author, double price, int count);

    // getter & setter
    [[nodiscard]] const string &getName() const;
    void setName(const string &name);
    [[nodiscard]] const string &getPublisher() const;
    void setPublisher(const string &publisher);
    [[nodiscard]] const string &getIsbn() const;
    void setIsbn(const string &isbn);
    [[nodiscard]] const string &getAuthor() const;
    void setAuthor(const string &author);
    [[nodiscard]] int getPrice() const;
    void setPrice(int price);
    [[nodiscard]] int getCount() const;
    void setCount(int count);

    [[nodiscard]] bool matches(const BookInfo &bookInfo) const;

    friend ostream &operator<<(ostream &os, const StockedBook &book);
};


#endif //LIBRARYMANAGERSYSTEM_STOCKEDBOOK_H
