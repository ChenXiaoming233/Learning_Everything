// 对字符串进行分词: sstream or 手动遍历

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// []sstream
vector<string> seperate1(string &str)
{
    string word;
    vector<string> result;

    stringstream ss(str);          // 将字符串放入输入输出流中
    while (getline(ss, word, ' ')) // ss 为指定的输入流；word 存放读取结果；' '（可选参数）作为分隔符指定读取停止位置，本身不被读入
    {
        if (!word.empty()) // **避免多个空格导致的空串**
            result.push_back(word);
    }
    return result;
}

// []手动遍历
vector<string> seperate2(string &str)
{
    string word;
    vector<string> result;

    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        word += c; // 将当前字符追加到 word 末尾累积
        if (c == ' ')
        {
            result.push_back(word);
            word.clear();
        }
    }
    if (!word.empty())
    { // **最后一个单词结尾没有空格**
        result.push_back(word);
    }
    return result;
}

int main()
{
    string str;
    getline(cin, str); // **读取整行内容**

    vector<string> result;
    result = seperate2(str);

    for (int i = result.size() - 1; i >= 0; i--)
    {
        cout << (i == result.size() - 1 ? "" : " ") << result[i] << 1 << endl;
    }
    return 0;
}
