// vector 存储自定义元素时需自定义排序规则
// vector<struct>

#include <bits/stdc++.h>

using namespace std;

struct Person
{
    long int no;
    int d;
    int c;
    int total;
    bool operator<(const Person &other) const // [] 重载 operator< 定义排序规则
    {
        if (total != other.total)
            return total > other.total;
        else if (d != other.d)
            return d > other.d;
        else
            return no < other.no;
    }
};

int main()
{
    int n, l, h;
    cin >> n >> l >> h;
    vector<Person> p1;
    vector<Person> p2;
    vector<Person> p3;
    vector<Person> p4;
    for (int i = 0; i < n; i++)
    {
        Person p;
        cin >> p.no >> p.d >> p.c;
        if (p.d < l or p.c < l)
            continue;
        else if (p.d >= h and p.c >= h)
        {
            p.total = p.d + p.c;
            p1.push_back(p);
        }
        else if (p.d >= h and p.c < h)
        {
            p.total = p.d + p.c;
            p2.push_back(p);
        }
        else if (p.d < h and p.c < h and p.d >= p.c)
        {
            p.total = p.d + p.c;
            p3.push_back(p);
        }
        else if (p.d >= l and p.c >= l)
        {
            p.total = p.d + p.c;
            p4.push_back(p);
        }
    }
    sort(p1.begin(), p1.end());
    /* [] 提供比较函数或 lambda 表达式制定排序规则
    sort(p1.begin(), p2.end(), [](const Person &a, const Person &b) {
        return a.total > b.total;
    });
    */
    sort(p2.begin(), p2.end());
    sort(p3.begin(), p3.end());
    sort(p4.begin(), p4.end());

    cout << p1.size() + p2.size() + p3.size() + p4.size() << endl;
    for (int i = 0; i < p1.size(); i++)
        cout << p1[i].no << " " << p1[i].d << " " << p1[i].c << endl;
    // cout << endl;
    for (int i = 0; i < p2.size(); i++)
        cout << p2[i].no << " " << p2[i].d << " " << p2[i].c << endl;
    // cout << endl;
    for (int i = 0; i < p3.size(); i++)
        cout << p3[i].no << " " << p3[i].d << " " << p3[i].c << endl;
    // cout << endl;
    for (int i = 0; i < p4.size(); i++)
        cout << p4[i].no << " " << p4[i].d << " " << p4[i].c << endl;
}