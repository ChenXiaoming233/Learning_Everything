#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
    // 创建容器
    deque<string> dq1;

    // 尾增元素
    dq1.push_back("梨");
    dq1.push_back("苹果");
    dq1.push_back("香蕉");
    dq1.push_back("橙子");

    // 首增元素
    dq1.push_front("西瓜");

    // 尾删元素
    dq1.pop_back();

    // 下标访问
    for (int i = 0; i < dq1.size(); i++)
        cout << dq1[i] << " ";
    cout << endl;

    // 迭代器访问
    for (deque<string>::iterator it = dq1.begin(); it != dq1.end(); it++)
        cout << *it << " ";
    cout << endl;

    // 清空容器
    dq1.clear();

    // 判空
    if (dq1.empty())
        cout << "空" << endl;
    else
        cout << "不空" << endl;

    return 0;
}