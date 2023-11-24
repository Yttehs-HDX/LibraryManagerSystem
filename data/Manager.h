#ifndef LIBRARYMANAGERSYSTEM_MANAGER_H
#define LIBRARYMANAGERSYSTEM_MANAGER_H

#include <iostream>
#include "BookList.h"

using namespace std;

class Manager {
public:
    BookList instance;
    // 菜单
    void menu();

    // 销售图书
    void saleBook();

    // 添加图书
    void addBook();

    // 查询图书
    void queryBook();

    // 修改图书
    void updateBook();

    // 删除图书
    void deleteBook();

    // 统计图书
    void sumBooks();
};


#endif //LIBRARYMANAGERSYSTEM_MANAGER_H
