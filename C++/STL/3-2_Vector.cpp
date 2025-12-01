#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 构造
void test0()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    vector<int> v2(v1.begin(), v1.end()); // 将 v(begin(), end()) 区间中的元素拷贝给本身
    printVector(v2);

    vector<int> v3(10, 100); // 将 n 个 elem 拷贝给本身
    printVector(v3);

    vector<int> v4(v3); // 拷贝构造函数
    printVector(v4);
}

// 赋值
void test1()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    vector<int> v2;
    v2 = v1;
    printVector(v2);

    vector<int> v3;
    v3.push_back(1);
    v3.assign(v1.begin(), v1.end()); // 将 [beg, end) 左闭右开区间中的数据拷贝赋值给本身, vector 重新分配, 不保留原有数据
    printVector(v3);

    vector<int> v4;
    v4.assign(10, 100); // 将 n 个 elem 拷贝赋值给本身
    printVector(v4);
}

// 容量和大小
void test2()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    if (v1.empty())
    {
        cout << "v1 is empty." << endl;
    }
    else
    {
        cout << "v1 isn't empty." << endl;
        cout << "v1's capacity is = " << v1.capacity() << endl; // 容器的容量
        cout << "v1's size is = " << v1.size() << endl;         // 容器中元素的个数
    }

    v1.resize(5); // resize 重新指定大小，若指定的更大则重新分配内存，并用 0 填充新位置；若更小则删除元素，但不会改变 vector 的长度
    printVector(v1);
    v1.resize(15, 10); // 若容器变长，则以指定的 elem 值填充新位置
    printVector(v1);
}

// 插入和删除
void test3()
{
    vector<int> v1;
    for (int i = 0; i < 9; i++)
    {
        v1.push_back(i);
    }
    // 尾删与尾删
    v1.push_back(9);
    printVector(v1);

    v1.pop_back();
    printVector(v1);

    // 插入
    v1.insert(v1.begin(), 100); // 在迭代器指向的位置插入元素 ele
    printVector(v1);

    v1.insert(v1.begin(), 2, 100); // 在迭代器指向的位置插入 count 个元素 ele
    printVector(v1);

    // 删除
    v1.erase(v1.begin()); // 删除迭代器指向的元素
    printVector(v1);

    // 清空
    v1.erase(v1.begin(), v1.end());
    v1.clear();
    printVector(v1);
}

// 数据存取
void test4()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1.at(i) << " "; // 返回索引 idx 所指的数据
    }
    cout << endl;

    cout << "v1's first element is: " << v1.front() << endl;
    cout << "v1's last element is: " << v1.back() << endl;
}

// 互换容器
void test5()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v2.push_back(v1.at(9 - i));
    }
    printVector(v2);
    v2.swap(v1); // 互换容器
    printVector(v1);
    printVector(v2);
}

void test6()
{
    vector<int> v;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
    }

    cout << "v's capacity is: " << v.capacity() << endl;
    cout << "v's size is: " << v.size() << endl;

    v.resize(3);

    cout << "v's capacity is: " << v.capacity() << endl;
    cout << "v's size is: " << v.size() << endl;

    // 收缩内存
    vector<int>(v).swap(v); // 等价于 vector<int> temp(v), 对象为匿名对象，其所在语句结束后被立即销毁

    cout << "v's capacity is: " << v.capacity() << endl; // 由于 v.size() == 3，temp 对象只拷贝其前 3 个元素，swap() 后 v 接管了 temp 的内存
    cout << "v's size is: " << v.size() << endl;
}

// 预留空间
void test7()
{
    vector<int> v;
    // v.reserve(100000);
    int num = 0;
    int *p = NULL;
    for (int i = 0; i < 10000000; i++)
    {
        v.push_back(i);
        if (p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }
    cout << "num:" << num << endl;
}

int main()
{
    test7();
    return 0;
}
