#include <bits/stdc++.h>

using namespace std;

int pos, pos2, n;
string::iterator it;

int main()
{
    // > 构造与赋值
    string str = "abcdefghijklmn";
    // *
    const char *c_str = "hello world";
    string str(c_str); // 将 c_string 转换为 string

    string str2(str); // 拷贝构造

    string str(n, 'c'); // 使用 n 个字符 c 初始化 str

    str.assign(n, 'c'); // 使用 n 个字符 c 赋值给 str
    // *
    str.assign(str2, n); // 把字符串 str2 的前 n 个字符赋值给 str

    // > 拼接
    str += str2; // 将 str2 连接到 str 的结尾
    str.append(str2);
    // *
    str.append(str2, pos, n); // 从 str2 的下标 pos 开始截取 n 个字符，拼接到 str 的末尾

    // > 遍历
    for (int i = 0; i < str.length(); i++)
    {
        cout << str[i] << " ";
    }

    string::iterator it = str.begin() + 2;
    for (it; it != str.end(); it = it + 2)
    {
        cout << *it << " "; // 注意对 it 解引用
    }

    // > 查找与替换
    // find():
    int pos = str.find(str2);                // 返回 str2 在 str 中第一次出现的 pos, 若查找不到则返回 **string::npos**
    int pos = str.find(str2, pos);           // 查找 str2，从 pos 开始
    int pos = str.substr(pos, n).find(str2); // 在从 pos 开始的前 n 个字符中查找 str2
    int pos = str.rfind(str2);               // 从右往左查找
    // string::find 不支持直接使用迭代器作为参数

    // replace()
    str.replace(0, 5, str2);                         // 删除从 pos 开始 n 个字符，插入 str2
    str.replace(str.begin(), str.begin() + n, str2); // 删除 [first, last) 的字符，插入 str2

    // > 比较
    if (str < str2) // 逐字符按字典序比较，前缀相同比长度
        cout << "str2 is bigger." << endl;

    // compare()
    // *
    int ret = str.compare(str2); // = 返回 0, > 返回 1, < 返回 -1

    // > 插入与删除
    // insert()
    str.insert(pos, str2, pos2, n);           // 在 pos **之前** 的位置，插入 str2 从 pos2 开始的前 n 个字符
    str.insert(it, str2.begin(), str2.end()); // 在 it 的位置，插入 [first, last) 的字符

    // erase
    str.erase(pos, n);                         // 从 pos **之前** 的位置，开始删除 n 个字符
    str.erase(str2.begin(), str2.begin() + n); // 删除 [first, last) 的字符

    // > 子串
    string str2 = str.substr(pos, n); // 返回由 pos 开始的 n 个字符组成的字符串

    return 0;
}