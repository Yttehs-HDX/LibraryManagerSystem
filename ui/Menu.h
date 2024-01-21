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
    static Menu &getInstance(); // 单例模式

    // 展示菜单
    void showMenu();
    // 查找
    void findBook();
    // 增加
    void addBook();
    // 删除
    void removeBook();
    // 修改
    void modifyBook();
    // 销售
    void saleBook();
    // 统计
    void statisticAllBooks();

};


#endif //LIBRARYMANAGERSYSTEM_MENU_H
