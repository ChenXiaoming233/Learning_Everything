#include <iostream>
#include <list>
#include <string>
#include <iterator> // 用于 prev, next

using namespace std;

int main()
{
    // 提高 C++ IO 速度，虽非必须但养成好习惯
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string input_seq;
    // 使用 getline 读取一行，因为输入可能包含空格
    getline(cin, input_seq);

    list<char> text;
    // 初始化光标在开头
    auto cursor = text.begin();
    // 默认是插入模式
    bool insertMode = true;

    for (int i = 0; i < input_seq.size(); i++)
    {
        char ch = input_seq[i];
        switch (ch)
        {
        case '[': // Home
            cursor = text.begin();
            break;
        case ']': // End
            cursor = text.end();
            break;
        case '{': // Left Arrow
            if (cursor != text.begin())
            {
                cursor--;
            }
            break;
        case '}': // Right Arrow
            if (cursor != text.end())
            {
                cursor++;
            }
            break;
        case '-': // Insert
            insertMode = !insertMode;
            break;
        case '=': // Backspace
            if (cursor != text.begin())
            {
                // 删除光标前的一个元素
                // erase 返回被删除元素之后的迭代器，但在 list 中
                // 我们删除的是 cursor 前面的，cursor 本身不受影响，
                // 所以这里可以直接 erase(prev(cursor))
                text.erase(prev(cursor));
            }
            break;
        default: // 普通字符 (a-z, 空格 等)
            if (insertMode)
            {
                // 插入模式：在光标前插入，光标位置不变（依然指向新插入字符的后面那个元素）
                // std::list 的 insert 会把元素插在 iterator 指向位置的“前面”
                text.insert(cursor, ch);
            }
            else
            {
                // 替换模式
                if (cursor != text.end())
                {
                    // 如果不在末尾，覆盖当前字符，光标后移
                    *cursor = ch;
                    cursor++;
                }
                else
                {
                    // 如果在末尾，替换模式等同于插入模式（追加）
                    text.insert(cursor, ch);
                }
            }
            break;
        }
    }

    // 输出结果
    for (auto it = text.begin(); it != text.end(); ++it)
    {
        cout << *it;
    }
    // 题目要求最后一个字母后没有回车，所以这里不输出 endl

    return 0;
}