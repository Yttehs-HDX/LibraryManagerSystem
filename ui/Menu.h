#ifndef LIBRARYMANAGERSYSTEM_MENU_H
#define LIBRARYMANAGERSYSTEM_MENU_H

#include "../core/Manager.h"

using namespace std;

class Menu {
    Menu() {}
public:
    Menu(const Menu &) = delete;
    Menu(const Menu &&) = delete;
    Menu &operator=(const Menu &) = delete;
    Menu &operator=(const Menu &&) = delete;
    static Menu &getInstance(); // ����ģʽ

    // չʾ�˵�
    void showMenu();
    // ����
    void findBook();
    // ����
    void addBook();
    // ɾ��
    void removeBook();
    // �޸�
    void modifyBook();
    // ����
    void saleBook();
    // ͳ��
    void statisticAllBooks();

};


#endif //LIBRARYMANAGERSYSTEM_MENU_H
