#include <algorithm>
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

void VectorPrint(int val)
{
    cout << val << endl;
}

void test0()
{
    vector<int> v0;
    v0.push_back(10);
    v0.push_back(20);
    v0.push_back(30);
    v0.push_back(40);

    vector<int>::iterator pBegin = v0.begin();
    vector<int>::iterator pEnd = v0.end(); // ! .end指向对象最后一个元素的下一个元素！

    // 三种遍历方式
    while (pBegin != pEnd)
    {
        cout << *pBegin << endl;
        pBegin++;
    }

    for (vector<int>::iterator it = v0.begin(); it != v0.end(); it++)
    {
        cout << *it << endl;
    }

    for_each(v0.begin(), v0.end(), VectorPrint);
}

class Person
{
public:
    string mName;
    int mAge;
    Person(string name, int age)
    {
        mName = name;
        mAge = age;
    }
};

void test1()
{
    vector<Person> v1;
    Person p1("aaa", 10); // p1 是 test1 的栈上对象
    Person p2("bbb", 20);
    Person p3("ccc", 30);

    v1.push_back(p1);
    v1.push_back(p2);
    v1.push_back(p3);

    for (vector<Person>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        cout << (*it).mName << " " << (*it).mAge << endl; // ! 注意迭代器还原需要加括号！
    }
} // test1 结束后 p1p2p3 与 v1 均被销毁

void test2()
{
    vector<Person *> v2; // vetor 中存放指向对象 Person 的指针
    Person p1("aaa", 40);
    Person p2("bbb", 50);
    Person p3("ccc", 60);

    v2.push_back(&p1);
    v2.push_back(&p2);
    v2.push_back(&p3);

    for (vector<Person *>::iterator it = v2.begin(); it != v2.end(); it++) // it 是指向指针 Person* 的迭代器; *it 是指针 Person*; **it 是对象 Person
    {
        cout << (**it).mName << " " << (*it)->mAge << endl;
        // it->mName == Person*->mName
        // -> 本身包含了一次解引用，(*it)->mAge == (**it).mAge
    }
}

void test3()
{
    vector<int> v0[100];   // 一个长度固定为 100 的数组，每个元素都是一个可变长的 vector<int>
    vector<vector<int>> v; // 定义了一个元素类型为 vector<int> 的 vector

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    for (int i = 0; i < 4; i++)
    {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) // it
    {
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) // *it 本身又是一个 vector<int>
        {
            cout << *vit << " ";
        }
        cout << endl;
    }
}

int main()
{
    test3();
    return 0;
}
