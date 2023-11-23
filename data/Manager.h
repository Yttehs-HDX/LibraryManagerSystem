#ifndef LIBRARYMANAGERSYSTEM_MANAGER_H
#define LIBRARYMANAGERSYSTEM_MANAGER_H

#include <iostream>
#include "BookList.h"

using namespace std;

class Manager {
private:
    Manager() {} // 不可外露构造函数，C++没有静态类只能这样
public:
    // 菜单
    static void menu();

    // 销售图书
    static void saleBook();

    // 添加图书
    static void addBook();

    // 查询图书
    static void queryBook();

    // 修改图书
    static void updateBook();

    // 删除图书
    static void deleteBook();

    // 统计图书
    static void sumBooks();
};


#endif //LIBRARYMANAGERSYSTEM_MANAGER_H
