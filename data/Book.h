#ifndef LIBRARYMANAGERSYSTEM_BOOK_H
#define LIBRARYMANAGERSYSTEM_BOOK_H

#include <iostream>

using namespace std;

class Book {
private:
    string name{}; // ����
    string publisher{}; // ������
    string isbn{}; // ISBN��
    string author{}; // ����
    int count{}; // �����
    double price{}; // �۸�
public:
    // constructor
    Book(string name, string publisher, string isbn, string author, int count, double price);

    // setter
    // ��������
    Book &setName(const string &name);
    // ���ó�����
    Book &setPublisher(const string &publisher);
    // ����ISBN��
    Book &setIsbn(const string &isbn);
    // ��������
    Book &setAuthor(const string &author);
    // ���ÿ����
    Book &setCount(int count);
    // ���ü۸�
    Book &setPrice(double price);

    // getter
    // ��ȡ����
    [[nodiscard]] const string &getName() const;
    // ��ȡ������
    [[nodiscard]] const string &getPublisher() const;
    // ��ȡISBN��
    [[nodiscard]] const string &getIsbn() const;
    // ��ȡ����
    [[nodiscard]] const string &getAuthor() const;
    // ��ȡ�����
    [[nodiscard]] int getCount() const;
    // ��ȡ�۸�
    [[nodiscard]] double getPrice() const;
};

#endif //LIBRARYMANAGERSYSTEM_BOOK_H