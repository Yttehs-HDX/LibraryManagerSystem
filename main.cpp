#include "ui/Menu.h"

int main() {

    cout << "VERBOSE: ��ȡ�ļ�..." << endl;
    Manager::getInstance().readFile();
    cout << "VERBOSE: ��ȡ�ɹ���" << endl;

    Menu::getInstance().showMenu();

    cout << "VERBOSE: д���ļ�..." << endl;
    Manager::getInstance().writeFile();
    cout << "VERBOSE: д��ɹ���" << endl;

    return 0;
}