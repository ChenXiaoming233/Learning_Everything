// # 输入输出格式

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string str, str1;
    getline(cin, str1);
    getline(cin, str);
    vector<string> output(n);
    if(str.size() % n != 0){
        for(int i = 0; i < str.size() % n; i++){
            str += " ";
        }
    }
    for (int i = 0; i < str.size(); i++)
    {
        int no = i % n;
        output[no].push_back(str[i]);
        // ! 注意 push_back() 接受的是一个 char 或者一个 string 的单个字符，而不是 string 本身，不能使用 str.substr()!
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = output[i].size() - 1; j >= 0; j--)
        {
            cout << output[i][j];
        }
        cout << endl;
    }
}