#include "ui/Menu.h"

int main() {

    cout << "VERBOSE: 读取文件..." << endl;
    Manager::getInstance().readFile();
    cout << "VERBOSE: 读取成功。" << endl;

    Menu::getInstance().showMenu();

    cout << "VERBOSE: 写入文件..." << endl;
    Manager::getInstance().writeFile();
    cout << "VERBOSE: 写入成功。" << endl;

    return 0;
}