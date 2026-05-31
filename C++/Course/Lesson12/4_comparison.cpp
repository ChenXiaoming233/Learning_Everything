#include <iostream>
#include <vector>
#include <deque>
#include <list>
using namespace std;

// vector
void Vector()
{
    //  构建
    vector<int> v;
    for (int i = 1; i <= 10; ++i)
        v.push_back(i);

    // 首插
    v.insert(v.begin(), 0);

    // 尾插
    v.push_back(11);

    // 删除元素
    v.erase(v.begin() + 4);

    // 打印
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

// deque
void Deque()
{
    //  构建
    deque<int> d;
    for (int i = 1; i <= 10; ++i)
        d.push_back(i);

    // 首插
    d.push_front(0);

    // 尾插
    d.push_back(11);

    // 删除元素
    deque<int>::iterator it = d.begin();
    for (int i = 0; i < 4; ++i)
        ++it;
    d.erase(it);

    // 打印
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

// list
void List()
{
    //  构建
    list<int> l;
    for (int i = 1; i <= 10; ++i)
        l.push_back(i);

    // 首插
    l.push_front(0);

    // 尾插
    l.push_back(11);

    // 删除元素
    list<int>::iterator it = l.begin();
    for (int i = 0; i < 4; ++i)
        ++it;
    l.erase(it);

    // 打印
    for (list<int>::const_iterator it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

int main()
{
    Vector();
    Deque();
    List();

    return 0;
}