#include "Manager.h"

// �˵�
void Manager::menu() {
    cout << "��ӭ����ͼ��ݹ���ϵͳ" << endl;
    instance = BookList();
    instance.initBooks();
    while (true) {
        cout << "�˵���" << endl;
        cout << "1. ����ͼ��" << endl;
        cout << "2. ���ͼ��" << endl;
        cout << "3. ��ѯͼ��" << endl;
        cout << "4. �޸�ͼ��" << endl;
        cout << "5. ɾ��ͼ��" << endl;
        cout << "6. ͳ��ͼ��" << endl;
        cout << "�������˳�ϵͳ" << endl;
        cout << "����������ѡ��";
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
}
// ����ͼ��
void Manager::saleBook() {
    cout << "������ͼ��ISBN��";
    string isbn;
    cin >> isbn;
    instance.saleBook(isbn);
}
// ���ͼ��
void Manager::addBook() {
    cout << "������ͼ��ISBN��" << endl;
    string isbn;
    cin >> isbn;
    instance.addBook(isbn);
}
// ��ѯͼ��
void Manager::queryBook() {
    cout << "���������������" << endl;
    cout << "1. ����" << endl;
    cout << "2. ISBN" << endl;
    cout << "3. ����" << endl;
    cout << "4. ������" << endl;
    cout << "����������ѡ��";
    int choice;
    cin >> choice;
    string input;
    switch (choice) {
        case 1:
            cout << "�����룺����";
            cin >> input;
            instance.findBooksByName(input);
            break;
        case 2:
            cout << "�����룺ISBN";
            cin >> input;
            instance.findBookByIsbn(input);
            break;
        case 3:
            cout << "�����룺����";
            cin >> input;
            instance.findBooksByAuthor(input);
            break;
        case 4:
            cout << "�����룺������";
            cin >> input;
            instance.findBooksByPublisher(input);
            break;
        default:
            cout << "�Ƿ����룡" << endl;
    }
}
// �޸�ͼ��
void Manager::updateBook() {
    cout << "���������������" << endl;
    cout << "1. ����" << endl;
    cout << "2. ISBN" << endl;
    cout << "3. ����" << endl;
    cout << "4. ������" << endl;
    cout << "����������ѡ��";
    int choice;
    cin >> choice;
    string input;
    switch (choice) {
        case 1:
            cout << "�����룺����";
            cin >> input;
            instance.modifyBooksByName(input);
            break;
        case 2:
            cout << "�����룺ISBN";
            cin >> input;
            instance.modifyBooksByIsbn(input);
            break;
        case 3:
            cout << "�����룺����";
            cin >> input;
            instance.modifyBooksByAuthor(input);
            break;
        case 4:
            cout << "�����룺������";
            cin >> input;
            instance.modifyBooksByPublisher(input);
            break;
        default:
            cout << "�Ƿ����룡" << endl;
    }
}
// ɾ��ͼ��
void Manager::deleteBook() {
    cout << "������ISBN��" << endl;
    string isbn;
    cin >> isbn;
    instance.deleteBook(isbn);
}
// ͳ��ͼ��
void Manager::sumBooks() {
    cout << "���������������" << endl;
    cout << "1. �۸�" << endl;
    cout << "2. ����" << endl;
    cout << "3. ����" << endl;
    cout << "4. ������" << endl;
    cout << "����������ѡ��";
    int choice;
    cin >> choice;
    string input;
    switch (choice) {
        case 1:
            instance.showAllBooksByPrice();
            break;
        case 2:
            instance.showAllBooksByCount();
            break;
        case 3:
            instance.showAllBooksByAuthor();
            break;
        case 4:
            instance.showAllBooksByPublisher();
            break;
        default:
            cout << "�Ƿ����룡" << endl;
    }
}