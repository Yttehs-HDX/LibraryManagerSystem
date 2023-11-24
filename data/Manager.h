#ifndef LIBRARYMANAGERSYSTEM_MANAGER_H
#define LIBRARYMANAGERSYSTEM_MANAGER_H

#include <iostream>
#include "BookList.h"

using namespace std;

class Manager {
public:
    BookList instance;
    // �˵�
    void menu();

    // ����ͼ��
    void saleBook();

    // ���ͼ��
    void addBook();

    // ��ѯͼ��
    void queryBook();

    // �޸�ͼ��
    void updateBook();

    // ɾ��ͼ��
    void deleteBook();

    // ͳ��ͼ��
    void sumBooks();
};


#endif //LIBRARYMANAGERSYSTEM_MANAGER_H
