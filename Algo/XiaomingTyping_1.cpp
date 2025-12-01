#include <bits/stdc++.h>

using namespace std;

string input;
list<char> output;
bool isInsert = true;

int main()
{
    getline(cin, input);
    list<char>::iterator cursor = output.begin();
    for (int i = 0; i < input.size(); i++)
    {
        char ch = input[i];
        switch (ch)
        {
        case '[':
            cursor = output.begin();
            break;
        case ']':
            cursor = output.end();
            break;
        case '{':
            if (cursor != output.begin())
                cursor--;
            break;
        case '}':
            if (cursor != output.end())
                cursor++;
            break;
        case '-':
            isInsert = !isInsert;
            break;
        case '=':
            if (cursor != output.begin())
            {
                auto left = cursor;
                --left; // 题目要求删除光标左侧的值
                output.erase(left);
            }
            break;
        default:
            if (isInsert)
            {
                output.insert(cursor, ch);
            }
            else
            {
                if (cursor != output.end())
                {
                    *cursor = ch;
                    cursor++;
                }
                else
                {
                    output.insert(cursor, ch);
                }
            }
            break;
        }
    }

    for (auto it = output.begin(); it != output.end(); ++it)
    {
        cout << *it;
    }
}