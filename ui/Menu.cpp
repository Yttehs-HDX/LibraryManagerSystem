#include "Menu.h"
#include <iomanip>

#define WIDTH 22

Menu &Menu::getInstance() {
    static Menu instance;
    return instance;
}

void Menu::showMenu() {
    while (true) {
        cout << setfill('=') << setw(9) << "" << "(o.O)" << setw(10) << "" << endl;
        cout << setfill(' ');
        cout << "~" << left << setw(WIDTH) << "��ӭ����ͼ��ݹ���ϵͳ" << "~" << endl;
        cout << "-" << setw(WIDTH) << "    1. ��ѯͼ��" << "-" << endl;
        cout << "-" << setw(WIDTH) << "    2. ���ͼ��" << "-" << endl;
        cout << "-" << setw(WIDTH) << "    3. ɾ��ͼ��" << "-" << endl;
        cout << "-" << setw(WIDTH) << "    4. �޸�ͼ��" << "-" << endl;
        cout << "-" << setw(WIDTH) << "    5. ����ͼ��" << "-" << endl;
        cout << "-" << setw(WIDTH) << "    6. ͳ��ͼ��" << "-" << endl;
        cout << "-" << setw(WIDTH) << "    7. �˳�ϵͳ" << "-" << endl;
        cout << setfill('=') << setw(9) << "" << "(o.O)" << setw(10) << "" << endl;
        cout << "[���������ѡ��] >";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                findBook();
                break;
            case 2:
                addBook();
                break;
            case 3:
                removeBook();
                break;
            case 4:
                modifyBook();
                break;
            case 5:
                saleBook();
                break;
            case 6:
                statisticAllBooks();
                break;
            case 7:
                return;
            default:
                cout << "ERROR: �Ƿ����룡" << endl;
        }
        system("pause");
        system("cls");
    }
}

void Menu::findBook() {
    cout << "- 1.����" << endl;
    cout << "- 2.ISBN" << endl;
    cout << "- 3.����" << endl;
    cout << "- 4.������" << endl;
    cout << "[��������Ҫ��ѯ�����ݣ�] >";
    int choice;
    cin >> choice;
    BookInfo book;
    string name;
    string isbn;
    string author;
    string publisher;
    switch (choice) {
        case 1:
            cout << "[������������] >";
            cin >> name;
            book.setName(name);
            break;
        case 2:
            cout << "[������ISBN��] >";
            cin >> isbn;
            book.setIsbn(isbn);
            break;
        case 3:
            cout << "[���������ߣ�] >";
            cin >> author;
            book.setAuthor(author);
            break;
        case 4:
            cout << "[����������磺] >";
            cin >> publisher;
            book.setPublisher(publisher);
            break;
        default:
            cout << "ERROR: �Ƿ����룡" << endl;
    }
    list<int> books = Manager::getInstance().findBookIndexes(book);
    if (books.empty()) {
        cout << "WARN: ���޴��飡" << endl;
        return;
    }
    for (int i : books) {
        cout << Manager::getInstance().getBookByIndex(i) << endl;
    }
}

void Menu::addBook() {
    cout << "- ������������";
    string name;
    cin >> name;
    cout << "- ����������磺";
    string publisher;
    cin >> publisher;
    cout << "- ������ISBN��";
    string isbn;
    cin >> isbn;
    cout << "- ���������ߣ�";
    string author;
    cin >> author;
    cout << "- ������۸�";
    double price;
    cin >> price;
    cout << "- �������棺";
    int count;
    cin >> count;
    bool res = Manager::getInstance().addBook(StockedBook(name, publisher, isbn, author, price, count));
    if (res) {
        cout << "INFO: ��ӳɹ���" << endl;
    } else {
        cout << "WARN: ���ʧ�ܣ��Ѵ��ڸ��鱾��" << endl;
    }
    Manager::getInstance().writeFile();
}

void Menu::removeBook() {
    cout << "[������ISBN��] >";
    string isbn;
    cin >> isbn;
    list<int> indexes = Manager::getInstance().findBookIndexes(BookInfo("", "", isbn, ""));
    if (indexes.empty()) {
        cout << "WARN: ���޴��飡" << endl;
        return;
    }
    int index = indexes.front();
    Manager::getInstance().removeBook(index);
    cout << "INFO: ɾ���ɹ���" << endl;
    Manager::getInstance().writeFile();
}

void Menu::modifyBook() {
    cout << "[������ISBN��] >";
    string isbn;
    cin >> isbn;
    list<int> indexes = Manager::getInstance().findBookIndexes(BookInfo("", "", isbn, ""));
    if (indexes.empty()) {
        cout << "WARN: ���޴��飡" << endl;
        return;
    }
    int index = indexes.front();
    StockedBook oldBook = Manager::getInstance().getBookByIndex(index);
    string name = oldBook.getName();
    string publisher = oldBook.getPublisher();
    string author = oldBook.getAuthor();
    double price = oldBook.getPrice();
    int count = oldBook.getCount();
    int choice = -1;
    while (choice != 6) {
        cout << "- 1.����" << endl;
        cout << "- 2.������" << endl;
        cout << "- 3.����" << endl;
        cout << "- 4.�۸�" << endl;
        cout << "- 5.���" << endl;
        cout << "- 6.�˳�" << endl;
        cout << "[��������Ҫ�޸ĵ����ԣ�] >";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "[������������] >";
                cin >> name;
                break;
            case 2:
                cout << "[����������磺] >";
                cin >> publisher;
                break;
            case 3:
                cout << "[���������ߣ�] >";
                cin >> author;
                break;
            case 4:
                cout << "[������۸�] >";
                cin >> price;
                break;
            case 5:
                cout << "[�������棺] >";
                cin >> count;
                break;
            case 6:
                break;
            default:
                cout << "ERROR: �Ƿ����룡" << endl;
        }
    }
    Manager::getInstance().modifyBook(index, StockedBook(name, publisher, isbn, author, price, count));
    cout << "INFO: �޸ĳɹ���" << endl;
    Manager::getInstance().writeFile();
}

void Menu::saleBook() {
    cout << "[������ISBN��] >";
    string isbn;
    cin >> isbn;
    list<int> indexes = Manager::getInstance().findBookIndexes(BookInfo("", "", isbn, ""));
    if (indexes.empty()) {
        cout << "WARN: ���޴��飡" << endl;
        return;
    }
    int index = indexes.front();
    Manager::getInstance().saleBook(index);
    cout << "INFO: ����ɹ���" << endl;
    Manager::getInstance().writeFile();
}

void Menu::statisticAllBooks() {
    list<StockedBook> books = Manager::getInstance().getAllBooks();
    if (books.empty()) {
        cout << "WARN: ��ǰ��ͼ�飡" << endl;
        return;
    }
    cout << "- 1.�۸�" << endl;
    cout << "- 2.�����" << endl;
    cout << "- 3.����" << endl;
    cout << "- 4.������" << endl;
    cout << "[����������������ݣ�] >";
    int choice;
    cin >> choice;
    bool (*cmp)(const StockedBook &, const StockedBook &);
    switch (choice) {
        case 1:
            cmp = [](const StockedBook &a, const StockedBook &b) {
                return a.getPrice() < b.getPrice();
            };
            break;
        case 2:
            cmp = [](const StockedBook &a, const StockedBook &b) {
                return a.getCount() < b.getCount();
            };
            break;
        case 3:
            cmp = [](const StockedBook &a, const StockedBook &b) {
                return a.getAuthor() < b.getAuthor();
            };
            break;
        case 4:
            cmp = [](const StockedBook &a, const StockedBook &b) {
                return a.getPublisher() < b.getPublisher();
            };
            break;
        default:
            cout << "ERROR: �Ƿ����룡" << endl;
            return;
    }
    books.sort(cmp);
    for (const StockedBook &book : books) {
        cout << book << endl;
    }
}
