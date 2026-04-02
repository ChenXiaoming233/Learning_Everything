#include <iostream>
#include <string>
using namespace std;

class Email
{
private:
    string name1;
    string name2;

public:
    // 解析 Email 地址
    void read(string address)
    {
        int n = address.find('@');
        name1 = address.substr(0, n);
        name2 = address.substr(n + 1);
    }

    void print()
    {
        cout << name1 << " " << "@" << " " << name2;
    }
};

int main()
{
    Email e;
    string email;
    cin >> email;
    e.read(email);
    e.print();
    return 0;
}