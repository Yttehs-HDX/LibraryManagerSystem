#ifndef LIBRARYMANAGERSYSTEM_BOOKLIST_H
#define LIBRARYMANAGERSYSTEM_BOOKLIST_H

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Book.h"

#define FILEPATH "books"

class BookList {
private:
    // �洢�����鱾
    vector<Book> books {Book("123456789", "123456789", "123456789", "1", 0, 0)};
    // ��ӡ��Ϣ
    void printOneBook(const Book &book);
    void printBooks();

    // ���ң�����ָ���vector
    vector<Book> searchBooksByName(const string &name);
    Book * searchBookByIsbn(const string &isbn);
    vector<Book> searchBooksByAuthor(const string &author);
    vector<Book> searchBooksByPublisher(const string &publisher);

    // �޸�
    void modifyBooks(vector<Book> &buffer);
    void modifyOneBook(Book *book);
public:
    // ������Ϣ�����ļ��н�ͼ����Ϣ�������
    void initBooks();

    // ͼ����̣�����ǰ�����е�ͼ����Ϣ�����ļ���
    void saveAllBooks();

    // ͳ�ƹ��ܣ������ǰ���������ͼ�����������ϸ��Ϣ
    void showAllBooksByPrice();
    void showAllBooksByCount();
    void showAllBooksByAuthor();
    void showAllBooksByPublisher();

    // ��ѯ���ܣ��ɰ�������ISBN�š����ߡ���������в�ѯ
    void findBooksByName(const string &name);
    void findBookByIsbn(const string &isbn);
    void findBooksByAuthor(const string &author);
    void findBooksByPublisher(const string &publisher);

    // �޸Ĺ��ܣ��ɸ��ݲ�ѯ�������Ӧ�ļ�¼�����޸�
    void modifyBooksByName(const string &name);
    void modifyBooksByIsbn(const string &isbn);
    void modifyBooksByAuthor(const string &author);
    void modifyBooksByPublisher(const string &publisher);

    // ɾ�����ܣ���Ҫ���ͼ����Ϣ��ɾ��
    void deleteBook(const string &isbn);

    // ���۹���
    void sellBook(const string &isbn);

    // ��ӹ��ܣ���Ҫ���ͼ����Ϣ����ӣ�Ҫ��ISBN��Ψһ
    void addBook(const string &isbn);
};

#endif //LIBRARYMANAGERSYSTEM_BOOKLIST_H
