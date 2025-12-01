#include <bits/stdc++.h>

using namespace std;

// find() 搜索次数超过 1e8 时不建议使用 find()
void test01()
{

    vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i + 1);

    vector<int>::iterator it = find(v.begin(), v.end(), 5); // find() 返回指定值的迭代器，若无则返回 end()
    if (it == v.end())
        cout << "没有找到!" << endl;
    else
        cout << "找到:" << *it << endl;
}

class Person
{
public:
    Person(string name, int age) // 类的构造函数
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
    bool operator==(const Person &p) // 自定义数据类型使用 find() 需要重载 ==
    {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) // this 代表一个指针
            return true;
        else
            return false;
    }
};

void test02()
{
    vector<Person> v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    vector<Person>::iterator it = find(v.begin(), v.end(), p2);
    if (it == v.end())
        cout << "没有找到!" << endl;
    else
        cout << "找到姓名:" << it->m_Name << " 年龄: " << it->m_Age << endl;
}

// find_if()
class GreaterThan
{
public:
    GreaterThan(int threshold) // 类的构造函数，用于接收阈值参数
    {
        this->m_threshold = threshold;
    }

    bool operator()(const Person &p) const
    {
        return p.m_Age > m_threshold;
    }

private:
    int m_threshold;
};

void test03()
{
    vector<Person> v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    vector<Person>::iterator it = find_if(v.begin(), v.end(), GreaterThan(20)); //
    if (it == v.end())
        cout << "没有找到!" << endl;
    else
        cout << "找到姓名:" << it->m_Name << " 年龄: " << it->m_Age << endl;
}

// adjacent_find() 查找相邻重复元素
void test04()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    v.push_back(2);
    v.push_back(4);
    v.push_back(4);
    v.push_back(3);

    vector<int>::iterator it = adjacent_find(v.begin(), v.end());
    if (it == v.end())
        cout << "找不到!" << endl;

    else
        cout << "找到相邻重复元素为:" << *it << endl;
}

// binary_search() 查找指定元素是否存在 基于二分查找
void test05()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);

    bool ret = binary_search(v.begin(), v.end(), 2); // 只能返回 bool
    if (ret)
        cout << "找到了" << endl;
    else
        cout << "未找到" << endl;
}

// count()
void test06()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);

    int num = count(v.begin(), v.end(), 4);
    cout << "4的个数为： " << num << endl;
}

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
    bool operator==(const Person &p)
    {
        if (this->m_Age == p.m_Age)
            return true;
        else
            return false;
    }
};

void test02()
{
    vector<Person> v;
    Person p1("刘备", 35);
    Person p2("关羽", 35);
    Person p3("张飞", 35);
    Person p4("赵云", 30);
    Person p5("曹操", 25);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    Person p("诸葛亮", 35);

    int num = count(v.begin(), v.end(), p);
    cout << "num = " << num << endl;
}

// count_if()
bool Greater4(int val)
{
    return val >= 4;
}

void test01()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);

    int num = count_if(v.begin(), v.end(), Greater4); // 传入普通函数时无需加 (), 因为函数名本身会隐式转换成函数指针
    cout << "大于4的个数为： " << num << endl;
}

class AgeLess35
{
public:
    bool operator()(const Person &p)
    {
        return p.m_Age < 35;
    }
};

void test02()
{
    vector<Person> v;

    Person p1("刘备", 35);
    Person p2("关羽", 35);
    Person p3("张飞", 35);
    Person p4("赵云", 30);
    Person p5("曹操", 25);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    int num = count_if(v.begin(), v.end(), AgeLess35());
    cout << "小于35岁的个数：" << num << endl;
}

int main()
{
    test03();
    return 0;
}