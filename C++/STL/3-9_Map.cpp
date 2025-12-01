#include <map>
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

void printMap(map<int, int> &m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << (*it).first << " " << it->second << endl; // first 与 second 分别固定指代 key 与 value
    }
    cout << endl;
}

struct Node
{
    int x, y;
    // 使用自定义结构体作为 key 时需要在结构体中重载小于号，因为 map 的结构基于红黑树的比较关系实现
    bool operator<(const Node &u) const
    {
        return x == u.x ? y < u.y : x < u.x;
    }
};

// 构造和赋值
void test0()
{
    // map<key, value> 一个 key 唯一对应一个 value, 不同的 key 可能对应相同的 value
    map<int, int> m;
    map<Node, int> mp_Node_int;

    m.insert(pair<int, int>(1, 10)); // pair 表示键值对
    m.insert({1, 20});               // 插入一个已经存在的 key 时，第二次插入会失败（key 值必须是唯一的）
    m[2] = 20;
    m[3] = 30;
    printMap(m);

    map<int, int> m2(m); // 拷贝构造
    printMap(m2);

    map<int, int> m3 = m2;
    printMap(m3);
}

// 大小和交换
void test1()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));

    if (m.empty())
    {
        cout << "m is empty." << endl;
    }
    else
    {
        cout << "m isn't empty." << endl;
        cout << "m's size is: " << m.size() << endl;
    }

    map<int, int> m2;
    m2.insert(pair<int, int>(4, 100));
    m2.insert(pair<int, int>(5, 200));
    m2.insert(pair<int, int>(6, 300));
    m.swap(m2);
    printMap(m);
    printMap(m2);
}

// 插入和删除
void test2()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(map<int, int>::value_type(3, 30));
    m.insert({4, 40});
    m[5] = 50;
    printMap(m);

    m.erase(m.begin()); // 删除迭代器 pos 所指向的元素，返回下一个元素的迭代器
    printMap(m);
    m.erase(3); // 删除指定 key 的元素，返回被删除的元素个数 (0 或 1)
    printMap(m);
    map<int, int>::iterator it = m.end();
    it--;
    it--;
    m.erase(m.begin(), it); // 删除一个区间，返回下一个元素的迭代器
    printMap(m);

    m.clear();
    printMap(m);
}

// 查找和统计
void test3()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(3, 30));
    map<int, int>::iterator pos = m.find(3); // 查找 key，返回该键的元素的迭代器，不存在则返回 **set.end()**;

    // 进行取值操作时一定要保证其对应的 key 是存在的
    if (m.find(3) != m.end())
    {
        cout << m[3] << endl;
    }
    if (m.count(4))
    {
        cout << m[4] << endl;
    }

    cout << m.count(3) << endl; // 统计指定 key 在 map 中出现的次数（0 或 1）
    cout << m.count(4) << endl;
}

// 排序
struct MapCompare
{                                         // 对 key 进行降序排序，map 本身无法对 value 进行排序
    bool operator()(int v1, int v2) const // 比较器必须是可被 const 调用的函数对象， operator() 必须是一个 const 成员函数
    {
        return v1 > v2;
    }
};

void printMap2(map<int, int, MapCompare> & m) // 为每种类型写重载函数
{
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << (*it).first << " " << it->second << endl; // first 与 second 分别固定指代 key 与 value
    }
    cout << endl;
}

void test5()
{
    map<int, int, MapCompare> m;    // 指定了 m 的比较器类型
    map<int, int, greater<int>> m2; // 倒序排列也可以直接使用标准比较器

    m.insert({1, 10});
    m.insert({2, 20});
    m.insert({3, 30});
    m.insert({4, 40});
    m.insert({5, 50});

    // printMap(m); // 错误！printMap 只接受默认比较器的 map, 与 m 不是相同的类型
    printMap2(m);
}

int main()
{
    test3();

    return 0;
}