#include "Manager.h"

#include <fstream>

Manager &Manager::getInstance() {
    static Manager instance;
    return instance;
}

list<int> Manager::findBookIndexes(const BookInfo& matcher) {
    list<int> indexes;
    for (const StockedBook& stockedBook : stockedBooks) {
        if (stockedBook.matches(matcher)) {
            indexes.push_back(stockedBook.getIndex());
        }
    }
    return indexes;
}

StockedBook &Manager::getBookByIndex(int index) {
    auto it = stockedBooks.begin();
    advance(it, index);
    return *it;
}

bool Manager::addBook(StockedBook newStockedBook) {
    BookInfo matcher("", "", newStockedBook.getIsbn(), "");
    list<int> indexes = findBookIndexes(matcher);
    if (!indexes.empty()) return false;
    newStockedBook.setIndex((int)stockedBooks.size());
    stockedBooks.push_back(newStockedBook);
    return true;
}

void Manager::removeBook(int index) {
    auto it = stockedBooks.begin();
    advance(it, index);
    stockedBooks.erase(it);
    for (auto i = it; i != stockedBooks.end(); ++i) {
        i->setIndex(i->getIndex() - 1);
    }
}

void Manager::modifyBook(int index, const StockedBook &newStockedBook) {
    auto it = stockedBooks.begin();
    advance(it, index);
    it->setName(newStockedBook.getName());
    it->setAuthor(newStockedBook.getAuthor());
    it->setPublisher(newStockedBook.getPublisher());
    it->setIsbn(newStockedBook.getIsbn());
    it->setPrice(newStockedBook.getPrice());
    it->setCount(newStockedBook.getCount());
}

void Manager::saleBook(int index) {
    auto it = stockedBooks.begin();
    advance(it, index);
    it->setCount(it->getCount() - 1);
}

list<StockedBook> Manager::getAllBooks() {
    return stockedBooks;
}

void Manager::readFile() {
    ifstream file(FILEPATH, ios::in);
    string name;
    string publisher;
    string isbn;
    string author;
    int price;
    int count;
    int index = 0;
    if (file.is_open()) {
        while (file >> name >> publisher >> isbn >> author >> price >> count) {
            StockedBook stockedBook(name, publisher, isbn, author, price, count);
            stockedBook.setIndex(index++);
            stockedBooks.push_back(stockedBook);
        }
    }
    file.close();
}

void Manager::writeFile() {
    ofstream file(FILEPATH, ios::out);
    if (file.is_open()) {
        for (const StockedBook &stockedBook : stockedBooks) {
            file << stockedBook.getName() << " "
            << stockedBook.getPublisher() << " "
            << stockedBook.getIsbn() << " "
            << stockedBook.getAuthor() << " "
            << stockedBook.getPrice() << " "
            << stockedBook.getCount() << endl;
        }
    }
    file.close();
}
