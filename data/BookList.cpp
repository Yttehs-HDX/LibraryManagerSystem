#include "BookList.h"

// 读出信息：从文件中将图书信息读入程序
void BookList::readAllBooks() {
    ifstream file(FILEPATH, ios::in);
    string name;
    string publisher;
    string isbn;
    string author;
    int count;
    double price;
    if (file.is_open()) {
        while (file >> name >> publisher >> isbn >> author >> count >> price) {
            books.emplace_back(name, publisher, isbn, author, count, price);
        }
    }
    books.erase(books.end());
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
// 打印信息
void BookList::printOneBook(const Book &book) {
    cout << book << endl;
}
void BookList::printBooks() {
    if (books.empty()) {
        cout << "当前书库中没有图书！" << endl;
        return;
    }
    for (const Book &book : books) {
        printOneBook(book);
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
// 查找，返回指针或vector
vector<Book> BookList::searchBooksByName(const string &name) {
    vector<Book> buffer;
    for (const Book &book : books) {
        if (book.getName() == name) {
            buffer.push_back(book);
        }
    }
    return buffer;
}
Book *BookList::searchBookByIsbn(const string &isbn) {
    for (Book &book : books) {
        if (book.getIsbn() == isbn) {
            return &book;
        }
    }
    return nullptr;
}
vector<Book> BookList::searchBooksByAuthor(const string &author) {
    vector<Book> buffer;
    for (const Book &book : books) {
        if (book.getAuthor() == author) {
            buffer.push_back(book);
        }
    }
    return buffer;
}
vector<Book> BookList::searchBooksByPublisher(const string &publisher) {
    vector<Book> buffer;
    for (const Book &book : books) {
        if (book.getPublisher() == publisher) {
            buffer.push_back(book);
        }
    }
    return buffer;
}
// 修改
void BookList::modifyOneBook(Book *book) {
    cout << "请输入想修改的信息：" << endl;
    cout << "1. 书名" << endl;
    cout << "2. 出版社" << endl;
    cout << "3. ISBN" << endl;
    cout << "4. 作者" << endl;
    cout << "5. 库存量" << endl;
    cout << "6. 价格" << endl;
    cout << "0. 返回" << endl;
    int choice;
    cin >> choice;
    cout << "请输入新值：";
    string input1;
    int input2;
    switch (choice) {
        case 0:
            break;
        case 1:
            cin >> input1;
            book->setName(input1);
            break;
        case 2:
            cin >> input1;
            book->setPublisher(input1);
            break;
        case 3:
            cin >> input1;
            book->setIsbn(input1);
            break;
        case 4:
            cin >> input1;
            book->setAuthor(input1);
            break;
        case 5:
            cin >> input2;
            book->setCount(input2);
            break;
        case 6:
            cin >> input2;
            book->setPrice(input2);
            break;
        default:
            cout << "非法输入！" << endl;
            return;
    }
    cout << "修改成功。" << endl;
}
void BookList::modifyBooks(vector<Book> &buffer) {
    if (buffer.empty()) {
        cout << "该标题不存在！" << endl;
    } else {
        int num = 1;
        for (const Book &book : books) {
            cout << num++ << " ";
            printOneBook(book);
        }
        cout << "请输入你想要修改的序号：";
        int index;
        cin >> index;
        if (index < 0 && index > num) {
            cout << "非法输入！" << endl;
            return;
        }
        modifyOneBook(&buffer[index]);
        saveAllBooks();
    }
}
// 查询功能：可按书名、ISBN号、作者、出版社进行查询
void BookList::findBooksByName(const string &name) {
    vector<Book> buffer = searchBooksByName(name);
    if (buffer.empty()) {
        cout << "该标题不存在！" << endl;
    } else {
        int num = 1;
        for (const Book &book : books) {
            cout << num++ << " ";
            printOneBook(book);
        }
    }
}
void BookList::findBookByIsbn(const string &isbn) {
    Book *target = searchBookByIsbn(isbn);
    if (target != nullptr) {
        printOneBook(*target);
    } else {
        cout << "该标题不存在！" << endl;
    }
}
void BookList::findBooksByAuthor(const string &author) {
    vector<Book> buffer = searchBooksByAuthor(author);
    if (buffer.empty()) {
        cout << "该标题不存在！" << endl;
    } else {
        int num = 1;
        for (const Book &book : books) {
            cout << num++ << endl;
            printOneBook(book);
        }
    }
}
void BookList::findBooksByPublisher(const string &publisher) {
    vector<Book> buffer = searchBooksByPublisher(publisher);
    if (buffer.empty()) {
        cout << "该标题不存在！" << endl;
    } else {
        int num = 1;
        for (const Book &book : books) {
            cout << num++ << " ";
            printOneBook(book);
        }
    }
}
// 修改功能：可根据查询结果对相应的记录进行修改
void BookList::modifyBooksByName(const string &name) {
    vector<Book> buffer = searchBooksByName(name);
    modifyBooks(buffer);
}
void BookList::modifyBooksByIsbn(const string &isbn) {
    Book *book = searchBookByIsbn(isbn);
    modifyOneBook(book);
}
void BookList::modifyBooksByAuthor(const string &author) {
    vector<Book> buffer = searchBooksByAuthor(author);
    modifyBooks(buffer);
}
void BookList::modifyBooksByPublisher(const string &publisher) {
    vector<Book> buffer = searchBooksByPublisher(publisher);
    modifyBooks(buffer);
}
// 删除功能：主要完成图书信息的删除
void BookList::deleteBook(const string &isbn) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getIsbn() == isbn) {
            books.erase(it);
            cout << "删除成功。" << endl;
            saveAllBooks();
            return;
        }
    }
    cout << "该标题不存在！" << endl;
}
// 销售功能：根据ISBN确定书本并将书本数量减一
void BookList::saleBook(const string &isbn) {
    Book *target = searchBookByIsbn(isbn);
    if (target != nullptr) {
        if (target->getCount() > 0) {
            target->setCount(target->getCount() - 1);
            cout << "购买成功。" << endl;
            saveAllBooks();
        } else {
            deleteBook(isbn);
            cout << "购买失败，该书本已售罄！" << endl;
        }
    } else {
        cout << "购买失败，该书本不存在！" << endl;
    }
}
// 添加功能：主要完成图书信息的添加，要求ISBN号唯一
void BookList::addBook(const string &isbn) {
    Book *target = searchBookByIsbn(isbn);
    if (target != nullptr) {
        cout << "添加失败，该书本已存在！" << endl;
    } else {
        cout << "请输入图书名称：";
        string name;
        cin >> name;
        cout << "请输入图书出版社：";
        string publisher;
        cin >> publisher;
        cout << "请输入图书作者：";
        string author;
        cin >> author;
        cout << "请输入图书数量：";
        int count;
        cin >> count;
        cout << "请输入图书价格：";
        double price;
        cin >> price;
        books.emplace_back(name, publisher, isbn, author, count, price);
        cout << "添加成功。" << endl;
        saveAllBooks();
    }
}