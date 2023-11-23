#include "Manager.h"

// 菜单
void Manager::menu() {
    cout << "欢迎来到图书馆管理系统" << endl;
    BookList::initBooks();
    while (true) {
        cout << "菜单：" << endl;
        cout << "1. 销售图书" << endl;
        cout << "2. 添加图书" << endl;
        cout << "3. 查询图书" << endl;
        cout << "4. 修改图书" << endl;
        cout << "5. 删除图书" << endl;
        cout << "6. 统计图书" << endl;
        cout << "其他：退出系统" << endl;
        cout << "请输入您的选择：";
        int input;
        cin >> input;
        switch (input) {
            case 1:
                saleBook();
                break;
            case 2:
                addBook();
                break;
            case 3:
                queryBook();
                break;
            case 4:
                updateBook();
                break;
            case 5:
                deleteBook();
                break;
            case 6:
                sumBooks();
                break;
            default:
                return;
        }
    }
    BookList::saveAllBooks();
}
// 销售图书
void Manager::saleBook() {
    cout << "请输入图书ISBN：";
    string isbn;
    cin >> isbn;
    BookList::sellBook(isbn);
}
// 添加图书
void Manager::addBook() {
    cout << "请输入图书ISBN：" << endl;
    string isbn;
    cin >> isbn;
    BookList::addBook(isbn);
}
// 查询图书
void Manager::queryBook() {
    cout << "请输入检索条件：" << endl;
    cout << "1. 书名" << endl;
    cout << "2. ISBN" << endl;
    cout << "3. 作者" << endl;
    cout << "4. 出版社" << endl;
    cout << "请输入您的选择：";
    int choice;
    cin >> choice;
    string input;
    switch (choice) {
        case 1:
            cout << "请输入：书名";
            cin >> input;
            BookList::findBooksByName(input);
            break;
        case 2:
            cout << "请输入：ISBN";
            cin >> input;
            BookList::findBookByIsbn(input);
            break;
        case 3:
            cout << "请输入：作者";
            cin >> input;
            BookList::findBooksByAuthor(input);
            break;
        case 4:
            cout << "请输入：出版社";
            cin >> input;
            BookList::findBooksByPublisher(input);
            break;
        default:
            cout << "非法输入！" << endl;
    }
}
// 修改图书
void Manager::updateBook() {
    cout << "请输入检索条件：" << endl;
    cout << "1. 书名" << endl;
    cout << "2. ISBN" << endl;
    cout << "3. 作者" << endl;
    cout << "4. 出版社" << endl;
    cout << "请输入您的选择：";
    int choice;
    cin >> choice;
    string input;
    switch (choice) {
        case 1:
            cout << "请输入：书名";
            cin >> input;
            BookList::modifyBooksByName(input);
            break;
        case 2:
            cout << "请输入：ISBN";
            cin >> input;
            BookList::modifyBooksByIsbn(input);
            break;
        case 3:
            cout << "请输入：作者";
            cin >> input;
            BookList::modifyBooksByAuthor(input);
            break;
        case 4:
            cout << "请输入：出版社";
            cin >> input;
            BookList::modifyBooksByPublisher(input);
            break;
        default:
            cout << "非法输入！" << endl;
    }
}
// 删除图书
void Manager::deleteBook() {
    cout << "请输入ISBN：" << endl;
    string isbn;
    cin >> isbn;
    BookList::deleteBook(isbn);
}
// 统计图书
void Manager::sumBooks() {
    cout << "请输入检索条件：" << endl;
    cout << "1. 价格" << endl;
    cout << "2. 数量" << endl;
    cout << "3. 作者" << endl;
    cout << "4. 出版社" << endl;
    cout << "请输入您的选择：";
    int choice;
    cin >> choice;
    string input;
    switch (choice) {
        case 1:
            BookList::showAllBooksByPrice();
        case 2:
            BookList::showAllBooksByCount();
        case 3:
            BookList::showAllBooksByAuthor();
            break;
        case 4:
            BookList::showAllBooksByPublisher();
            break;
        default:
            cout << "非法输入！" << endl;
    }
}