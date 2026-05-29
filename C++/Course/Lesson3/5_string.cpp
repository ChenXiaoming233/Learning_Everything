#include <iostream>
#include <string>
using namespace std;

class MyString
{
private:
    string data;

public:
    // 构造函数
    MyString() {}

    // 从 C 风格字符串构造
    MyString(const char *s) : data(s) {}

    // 返回长度
    int length() const
    {
        return data.size();
    }

    // 取子串：
    string sub(int start, int count) const
    {
        return data.substr(start, count);
    }

    // 查找子串
    int search(const char *sub) const
    {
        int pos = data.find(sub);
        if (pos == string::npos)
            return -1;
        else
            return int(pos);
    }

    // 连接字符串
    void connect(const MyString &other)
    {
        data += other.data;
    }

    // 打印
    void print() const
    {
        cout << data << endl;
    }
};

int main()
{
    MyString str;                       // 初始化为空字符串
    MyString str2("abc");               // 初始化为字符串“abc”
    cout << str2.length() << endl;      // 打印输出：3
    cout << str2.sub(1, 2) << endl;     // 打印输出：bc
    cout << str2.search("bc") << endl;  // 打印输出：1
    cout << str2.search("bcd") << endl; // 打印输出：-1

    str.connect(str2); // 将 str2 串接到 str 中
    str.print();       // 打印输出：abc

    MyString str3(str); // 拷贝构造
    str3.print();       // 打印输出：abc

    return 0;
}