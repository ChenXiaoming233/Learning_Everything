#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 创建容器
    vector<int> v1 = {10, 20, 30, 40, 50};

    // 添加元素
    v1.push_back(60);

    // 删除元素
    v1.erase(v1.begin());

    // 遍历容器
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
    cout << endl;

    // 输出总数
    cout << "总个数：" << v1.size() << endl;

    return 0;
}