#include "BookList.h"

// ������Ϣ�����ļ��н�ͼ����Ϣ�������
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
// ͼ����̣�����ǰ�����е�ͼ����Ϣ�����ļ���
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
// ��ӡ��Ϣ
void BookList::printOneBook(const Book &book) {
    cout << book << endl;
}
void BookList::printBooks() {
    if (books.empty()) {
        cout << "��ǰ�����û��ͼ�飡" << endl;
        return;
    }
    for (const Book &book : books) {
        printOneBook(book);
    }
}
// ͳ�ƹ��ܣ������ǰ���������ͼ�����������ϸ��Ϣ
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
// ���ң�����ָ���vector
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
// �޸�
void BookList::modifyOneBook(Book *book) {
    cout << "���������޸ĵ���Ϣ��" << endl;
    cout << "1. ����" << endl;
    cout << "2. ������" << endl;
    cout << "3. ISBN" << endl;
    cout << "4. ����" << endl;
    cout << "5. �����" << endl;
    cout << "6. �۸�" << endl;
    cout << "0. ����" << endl;
    int choice;
    cin >> choice;
    cout << "��������ֵ��";
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
            cout << "�Ƿ����룡" << endl;
            return;
    }
    cout << "�޸ĳɹ���" << endl;
}
void BookList::modifyBooks(vector<Book> &buffer) {
    if (buffer.empty()) {
        cout << "�ñ��ⲻ���ڣ�" << endl;
    } else {
        int num = 1;
        for (const Book &book : books) {
            cout << num++ << " ";
            printOneBook(book);
        }
        cout << "����������Ҫ�޸ĵ���ţ�";
        int index;
        cin >> index;
        if (index < 0 && index > num) {
            cout << "�Ƿ����룡" << endl;
            return;
        }
        modifyOneBook(&buffer[index]);
        saveAllBooks();
    }
}
// ��ѯ���ܣ��ɰ�������ISBN�š����ߡ���������в�ѯ
void BookList::findBooksByName(const string &name) {
    vector<Book> buffer = searchBooksByName(name);
    if (buffer.empty()) {
        cout << "�ñ��ⲻ���ڣ�" << endl;
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
        cout << "�ñ��ⲻ���ڣ�" << endl;
    }
}
void BookList::findBooksByAuthor(const string &author) {
    vector<Book> buffer = searchBooksByAuthor(author);
    if (buffer.empty()) {
        cout << "�ñ��ⲻ���ڣ�" << endl;
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
        cout << "�ñ��ⲻ���ڣ�" << endl;
    } else {
        int num = 1;
        for (const Book &book : books) {
            cout << num++ << " ";
            printOneBook(book);
        }
    }
}
// �޸Ĺ��ܣ��ɸ��ݲ�ѯ�������Ӧ�ļ�¼�����޸�
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
// ɾ�����ܣ���Ҫ���ͼ����Ϣ��ɾ��
void BookList::deleteBook(const string &isbn) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getIsbn() == isbn) {
            books.erase(it);
            cout << "ɾ���ɹ���" << endl;
            saveAllBooks();
            return;
        }
    }
    cout << "�ñ��ⲻ���ڣ�" << endl;
}
// ���۹��ܣ�����ISBNȷ���鱾�����鱾������һ
void BookList::saleBook(const string &isbn) {
    Book *target = searchBookByIsbn(isbn);
    if (target != nullptr) {
        if (target->getCount() > 0) {
            target->setCount(target->getCount() - 1);
            cout << "����ɹ���" << endl;
            saveAllBooks();
        } else {
            deleteBook(isbn);
            cout << "����ʧ�ܣ����鱾��������" << endl;
        }
    } else {
        cout << "����ʧ�ܣ����鱾�����ڣ�" << endl;
    }
}
// ��ӹ��ܣ���Ҫ���ͼ����Ϣ����ӣ�Ҫ��ISBN��Ψһ
void BookList::addBook(const string &isbn) {
    Book *target = searchBookByIsbn(isbn);
    if (target != nullptr) {
        cout << "���ʧ�ܣ����鱾�Ѵ��ڣ�" << endl;
    } else {
        cout << "������ͼ�����ƣ�";
        string name;
        cin >> name;
        cout << "������ͼ������磺";
        string publisher;
        cin >> publisher;
        cout << "������ͼ�����ߣ�";
        string author;
        cin >> author;
        cout << "������ͼ��������";
        int count;
        cin >> count;
        cout << "������ͼ��۸�";
        double price;
        cin >> price;
        books.emplace_back(name, publisher, isbn, author, count, price);
        cout << "��ӳɹ���" << endl;
        saveAllBooks();
    }
}