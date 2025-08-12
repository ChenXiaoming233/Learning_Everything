#include<iostream>
#include<cstdint> // 添加此行以包含 定宽整数 的定义
#include<cstdio> // 添加此行以包含 printf 函数的定义
#include<algorithm>
#include<vector>
 
using namespace std;
 
int main() {
    std::string a, b, slite, s;
    int result;
    a = "hajimi";
    b = "0721";
    result = a.compare(b);
    getline(cin,s);
    slite = s.substr(0,5);
    cout << slite << " " << result << endl;
    return 0;
}
