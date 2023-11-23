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
};


#endif //LIBRARYMANAGERSYSTEM_MANAGER_H
