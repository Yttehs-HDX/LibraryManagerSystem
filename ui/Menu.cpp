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
        cout << "~" << left << setw(WIDTH) << "欢迎来到图书馆管理系统" << "~" << endl;
        cout << "-" << setw(WIDTH) << "    1. 查询图书" << "-" << endl;
        cout << "-" << setw(WIDTH) << "    2. 添加图书" << "-" << endl;
        cout << "-" << setw(WIDTH) << "    3. 删除图书" << "-" << endl;
        cout << "-" << setw(WIDTH) << "    4. 修改图书" << "-" << endl;
        cout << "-" << setw(WIDTH) << "    5. 销售图书" << "-" << endl;
        cout << "-" << setw(WIDTH) << "    6. 统计图书" << "-" << endl;
        cout << "-" << setw(WIDTH) << "    7. 退出系统" << "-" << endl;
        cout << setfill('=') << setw(9) << "" << "(o.O)" << setw(10) << "" << endl;
        cout << "[请输入你的选择：] >";
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
                cout << "ERROR: 非法输入！" << endl;
        }
        system("pause");
        system("cls");
    }
}

void Menu::findBook() {
    cout << "- 1.书名" << endl;
    cout << "- 2.ISBN" << endl;
    cout << "- 3.作者" << endl;
    cout << "- 4.出版社" << endl;
    cout << "[请输入你要查询的依据：] >";
    int choice;
    cin >> choice;
    BookInfo book;
    string name;
    string isbn;
    string author;
    string publisher;
    switch (choice) {
        case 1:
            cout << "[请输入书名：] >";
            cin >> name;
            book.setName(name);
            break;
        case 2:
            cout << "[请输入ISBN：] >";
            cin >> isbn;
            book.setIsbn(isbn);
            break;
        case 3:
            cout << "[请输入作者：] >";
            cin >> author;
            book.setAuthor(author);
            break;
        case 4:
            cout << "[请输入出版社：] >";
            cin >> publisher;
            book.setPublisher(publisher);
            break;
        default:
            cout << "ERROR: 非法输入！" << endl;
    }
    list<int> books = Manager::getInstance().findBookIndexes(book);
    if (books.empty()) {
        cout << "WARN: 查无此书！" << endl;
        return;
    }
    for (int i : books) {
        cout << Manager::getInstance().getBookByIndex(i) << endl;
    }
}

void Menu::addBook() {
    cout << "- 请输入书名：";
    string name;
    cin >> name;
    cout << "- 请输入出版社：";
    string publisher;
    cin >> publisher;
    cout << "- 请输入ISBN：";
    string isbn;
    cin >> isbn;
    cout << "- 请输入作者：";
    string author;
    cin >> author;
    cout << "- 请输入价格：";
    double price;
    cin >> price;
    cout << "- 请输入库存：";
    int count;
    cin >> count;
    bool res = Manager::getInstance().addBook(StockedBook(name, publisher, isbn, author, price, count));
    if (res) {
        cout << "INFO: 添加成功。" << endl;
    } else {
        cout << "WARN: 添加失败，已存在该书本！" << endl;
    }
    Manager::getInstance().writeFile();
}

void Menu::removeBook() {
    cout << "[请输入ISBN：] >";
    string isbn;
    cin >> isbn;
    list<int> indexes = Manager::getInstance().findBookIndexes(BookInfo("", "", isbn, ""));
    if (indexes.empty()) {
        cout << "WARN: 查无此书！" << endl;
        return;
    }
    int index = indexes.front();
    Manager::getInstance().removeBook(index);
    cout << "INFO: 删除成功！" << endl;
    Manager::getInstance().writeFile();
}

void Menu::modifyBook() {
    cout << "[请输入ISBN：] >";
    string isbn;
    cin >> isbn;
    list<int> indexes = Manager::getInstance().findBookIndexes(BookInfo("", "", isbn, ""));
    if (indexes.empty()) {
        cout << "WARN: 查无此书！" << endl;
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
        cout << "- 1.书名" << endl;
        cout << "- 2.出版社" << endl;
        cout << "- 3.作者" << endl;
        cout << "- 4.价格" << endl;
        cout << "- 5.库存" << endl;
        cout << "- 6.退出" << endl;
        cout << "[请输入你要修改的属性：] >";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "[请输入书名：] >";
                cin >> name;
                break;
            case 2:
                cout << "[请输入出版社：] >";
                cin >> publisher;
                break;
            case 3:
                cout << "[请输入作者：] >";
                cin >> author;
                break;
            case 4:
                cout << "[请输入价格：] >";
                cin >> price;
                break;
            case 5:
                cout << "[请输入库存：] >";
                cin >> count;
                break;
            case 6:
                break;
            default:
                cout << "ERROR: 非法输入！" << endl;
        }
    }
    Manager::getInstance().modifyBook(index, StockedBook(name, publisher, isbn, author, price, count));
    cout << "INFO: 修改成功！" << endl;
    Manager::getInstance().writeFile();
}

void Menu::saleBook() {
    cout << "[请输入ISBN：] >";
    string isbn;
    cin >> isbn;
    list<int> indexes = Manager::getInstance().findBookIndexes(BookInfo("", "", isbn, ""));
    if (indexes.empty()) {
        cout << "WARN: 查无此书！" << endl;
        return;
    }
    int index = indexes.front();
    Manager::getInstance().saleBook(index);
    cout << "INFO: 购买成功！" << endl;
    Manager::getInstance().writeFile();
}

void Menu::statisticAllBooks() {
    list<StockedBook> books = Manager::getInstance().getAllBooks();
    if (books.empty()) {
        cout << "WARN: 当前无图书！" << endl;
        return;
    }
    cout << "- 1.价格" << endl;
    cout << "- 2.库存量" << endl;
    cout << "- 3.作者" << endl;
    cout << "- 4.出版社" << endl;
    cout << "[请输入你的排序依据：] >";
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
            cout << "ERROR: 非法输入！" << endl;
            return;
    }
    books.sort(cmp);
    for (const StockedBook &book : books) {
        cout << book << endl;
    }
}
