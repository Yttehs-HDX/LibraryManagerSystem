#include "BookList.h"

// 读出信息：从文件中将图书信息读入程序
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
// 图书存盘：将当前程序中的图书信息存入文件中
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

void BookList::printBooks() {
    for (const Book &book : books) {
        cout << book.getName()
             << " " << book.getPublisher()
             << " " << book.getIsbn()
             << " " << book.getAuthor()
             << " " << book.getCount()
             << " " << book.getPrice() << endl;
    }
}
// 统计功能：输出当前书库中所有图书的总数及详细信息
void BookList::showAllBooksByPrice() {
    sort(books.begin(), books.end(),
         [](const Book &a, const Book &b) {return a.getPrice() > b.getPrice();});
    printBooks();
}
void BookList::showAllBooksByCount() {
    sort(books.begin(), books.end(),
         [](const Book &a, const Book &b) {return a.getCount() > b.getCount();});
    printBooks();
}
void BookList::showAllBooksByAuthor() {
    sort(books.begin(), books.end(),
         [](const Book &a, const Book &b) {return a.getAuthor() > b.getAuthor();});
    printBooks();
}
void BookList::showAllBooksByPublisher() {
    sort(books.begin(), books.end(),
         [](const Book &a, const Book &b) {return a.getPublisher() > b.getPublisher();});
    printBooks();
}
// 销售功能
void BookList::sellBook(const string &isbn) {
    for (Book &book : books) {
        if (book.getIsbn() == isbn) {
            book.setCount(book.getCount() - 1);
            break;
        }
    }
}