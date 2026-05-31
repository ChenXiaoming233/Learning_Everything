#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
using namespace std;

struct Stu
{
    int id;
    string name;
    double score;
};

// 比较函数
bool cmp(const Stu &a, const Stu &b)
{
    return a.score > b.score;
}

int main()
{
    vector<Stu> stus;

    // 添加信息
    stus.push_back((Stu){1001, "张三", 85.5});
    stus.push_back((Stu){1002, "李四", 92.0});
    stus.push_back((Stu){1003, "王五", 58.5});
    stus.push_back((Stu){1004, "赵六", 45.0});
    stus.push_back((Stu){1005, "孙七", 78.0});

    // 降序排序
    sort(stus.begin(), stus.end(), cmp);

    // deque 缓存
    deque<Stu> top;
    for (int i = 0; i < 3 && i < stus.size(); ++i)
        top.push_back(stus[i]);

    // list存储
    list<Stu> end;
    for (int i = 0; i < stus.size(); ++i)
        if (stus[i].score < 60)
            end.push_back(stus[i]);

    // 打印全体
    for (int i = 0; i < stus.size(); ++i)
        cout << "学号:" << stus[i].id << " 姓名:" << stus[i].name << " 成绩:" << stus[i].score << endl;

    // 打印前三名
    for (deque<Stu>::iterator it = top.begin(); it != top.end(); ++it)
        cout << "学号:" << (*it).id << " 姓名:" << (*it).name << " 成绩:" << (*it).score << endl;

    // 打印不及格
    for (list<Stu>::iterator it = end.begin(); it != end.end(); ++it)
        cout << "学号:" << (*it).id << " 姓名:" << (*it).name << " 成绩:" << (*it).score << endl;

    return 0;
}