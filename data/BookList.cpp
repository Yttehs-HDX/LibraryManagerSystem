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
// 查询功能：可按书名、ISBN号、作者、出版社进行查询
Book *BookList::searchBookByName(const string &name) {
    for (Book &book : books) {
        if (book.getName() == name) {
            return &book;
        }
    }
    return nullptr;
}
Book *BookList::searchBookByIsbn(const string &isbn) {
    for (Book &book : books) {
        if (book.getIsbn() == isbn) {
            return &book;
        }
    }
    return nullptr;
}
Book *BookList::searchBookByAuthor(const string &author) {
    for (Book &book : books) {
        if (book.getAuthor() == author) {
            return &book;
        }
    }
    return nullptr;
}
Book *BookList::searchBookByPublisher(const string &publisher) {
    for (Book &book : books) {
        if (book.getPublisher() == publisher) {
            return &book;
        }
    }
    return nullptr;
}
// 销售功能：根据ISBN确定书本并将书本数量减一
void BookList::sellBook(const string &isbn) {
    Book *target = searchBookByIsbn(isbn);
    if (target != nullptr) {
        target->setCount(target->getCount() - 1);
        cout << "购买成功。" << endl;
    } else {
        cout << "购买失败，该书本不存在！" << endl;
    }
}

// 添加功能：主要完成图书信息的添加，要求ISBN号唯一
void BookList::addBook(const string &name, const string &publisher, const string &isbn, const string &author, int count, double price) {
    Book *target = searchBookByIsbn(isbn);
    if (target != nullptr) {
        cout << "添加失败，该书本已存在！" << endl;
    } else {
        books.emplace_back(name, publisher, isbn, author, count, price);
        cout << "添加成功。" << endl;
    }
}