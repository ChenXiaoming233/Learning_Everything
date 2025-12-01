#include <bits/stdc++.h>

using namespace std;

void printList(const list<int> &L)
{

    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 构造
void test01()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    printList(L1);

    list<int> L2(L1.begin(), L1.end()); // 构造函数将 [beg, end) 区间中的元素拷贝给本身
    printList(L2);

    list<int> L3(L2); // 拷贝构造函数
    printList(L3);

    list<int> L4(10, 1000); // 构造函数将 n 个 elem 拷贝给本身
    printList(L4);
}

// 赋值和交换
// 赋值
void test02()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    printList(L1);


    list<int> L2;
    L2 = L1;
    printList(L2);

    list<int> L3;
    L3.assign(L2.begin(), L2.end()); // 将 [beg, end) 区间中的数据拷贝赋值给本身。
    printList(L3);

    list<int> L4;
    L4.assign(10, 100); // 将 n 个 elem 拷贝赋值给本身。
    printList(L4);
}

// 交换
void test03()
{

    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    list<int> L2;
    L2.assign(10, 100);

    cout << "交换前： " << endl;
    printList(L1);
    printList(L2);

    cout << endl;

    L1.swap(L2);

    cout << "交换后： " << endl;
    printList(L1);
    printList(L2);
}

// 大小操作
void test04()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    if (L1.empty())
    {
        cout << "L1为空" << endl;
    }
    else
    {
        cout << "L1不为空" << endl;
        cout << "L1的大小为： " << L1.size() << endl;
    }

    L1.resize(10); // 重新指定容器的长度为 num；若容器变长，则以默认值填充新位置；若容器变短，则末尾超出容器长度的元素被删除。
    printList(L1);

    L1.resize(12, 0); // 重新指定容器的长度为 num；若容器变长，则以 elem 填充新位置；若容器变短，则末尾超出容器长度的元素被删除。
    printList(L1);
}

// 插入和删除
void test05()
{
    list<int> L;

    // 尾插
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);
    // 头插
    L.push_front(100);
    L.push_front(200);
    L.push_front(300);

    printList(L);

    // 尾删
    L.pop_back();
    printList(L);

    // 头删
    L.pop_front();
    printList(L);

    // 插入
    list<int>::iterator it = L.begin();
    L.insert(++it, 1000); // 在 pos 位置 **左侧** 插入 elem 元素的拷贝，返回的 pos 依然指向原元素
    printList(L);

    // 删除
    it = L.begin();
    L.erase(++it); // 直接删除 pos 位置的元素，返回的 pos 指向原位置的 **左侧**
    printList(L);

    // 移除
    L.push_back(10000);
    L.push_back(10000);
    L.push_back(10000);
    printList(L);
    L.remove(10000); // 删除容器中 **所有与 elem 值匹配** 的元素。
    printList(L);

    // 清空
    L.clear();
    printList(L);
}

// 数据存取
// ! 注意 list 容器的迭代器是双向迭代器，**不支持随机访问**
void test06()
{
    list<int> L1;

    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    // ! 注意 cout << L1.at(0) << endl; // 错误 不支持 at 访问数据
    // ! 注意 cout << L1[0] << endl; // 错误 不支持 [] 方式访问数据
    cout << "第一个元素为： " << L1.front() << endl;
    cout << "最后一个元素为： " << L1.back() << endl;

    list<int>::iterator it = L1.begin();
    // it = it + 1; // 错误，**不可以跳跃访问**，即使是 +1
    advance(it, 5);
}

// 指定排序方式
bool myCompare(int val1, int val2)
{
    return val1 > val2;
}

// 反转和排序
void test07()
{
    list<int> L;
    L.push_back(90);
    L.push_back(30);
    L.push_back(20);
    L.push_back(70);
    printList(L);

    // 反转容器的元素
    L.reverse();
    printList(L);

    // 排序
    L.sort(); // 默认的排序规则 从小到大
    printList(L);

    L.sort(myCompare); // 指定规则，从大到小
    printList(L);
}

int main()
{

    test01();

    system("pause");

    return 0;
}