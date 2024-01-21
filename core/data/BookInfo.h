#ifndef LIBRARYMANAGERSYSTEM_BOOKINFO_H
#define LIBRARYMANAGERSYSTEM_BOOKINFO_H

#include <iostream>

using namespace std;

class BookInfo {
    string name{}; // 书名
    string publisher{}; // 出版社
    string isbn{}; // ISBN号
    string author{}; // 作者
public:
    // constructor
    BookInfo() = default;
    BookInfo(string name, string publisher, string isbn, string author);

    // getter & setter
    [[nodiscard]] const string& getName() const;
    void setName(const string& name);
    [[nodiscard]] const string& getPublisher() const;
    void setPublisher(const string& publisher);
    [[nodiscard]] const string& getIsbn() const;
    void setIsbn(const string& isbn);
    [[nodiscard]] const string& getAuthor() const;
    void setAuthor(const string &author);

    // 判断匹配
    bool matches(const BookInfo &bookInfo) const;

    friend ostream &operator<<(ostream &os, const BookInfo &info);
};

#endif //LIBRARYMANAGERSYSTEM_BOOKINFO_H
