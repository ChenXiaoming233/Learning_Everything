#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct User
{
    string username;
    string password;
};

// 读取文件
vector<User> read(string &filename)
{
    vector<User> users;
    ifstream inFile(filename);

    string name, pwd;
    while (inFile >> name >> pwd)
    {
        User u = {name, pwd};
        users.push_back(u);
    }
    inFile.close();

    return users;
}

// 账号校验
bool check(vector<User> &users, string &name, string &pwd)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].username == name && users[i].password == pwd)
            return true;
    }
    return false;
}

int main()
{
    string filename = "users.txt";
    vector<User> users = read(filename);

    string username, password;
    bool loggedIn = false;

    while (!loggedIn)
    {
        cout << "用户名：";
        cin >> username;
        cout << "密码：";
        cin >> password;

        if (check(users, username, password))
        {
            cout << "欢迎您回来，" << username << "！" << endl;
            loggedIn = true;
        }
        else
            cout << "用户名或密码错误，请重新输入。" << endl;
    }
    return 0;
}