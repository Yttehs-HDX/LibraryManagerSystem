#include "BookList.h"

void BookList::initBooks() {
    ifstream file(FILEPATH, ios::in);
    string name;
    string publisher;
    string isbn;
    string author;
    int count;
    double price;
    if (file.is_open()) {
        while (file >> name >> publisher >> isbn >> author >> count >> price) {
            file >> name >> publisher >> isbn >> author >> count >> price;
            Book book(name, publisher, isbn, author, count, price);
            books.push_back(book);
        }
    }
    file.close();
}

void BookList::saveAllBooks() {
    ofstream file(FILEPATH, ios::out);
    if (file.is_open()) {
        for (const Book &book: books) {
            file << book.getName()
                 << " " << book.getPublisher()
                 << " " << book.getIsbn()
                 << " " << book.getAuthor()
                 << " " << book.getCount()
                 << " " << book.getPrice() << endl;
        }
    }
    file.close();
}