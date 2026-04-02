#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Student
{
private:
    int id;
    string name;
    int classNum;
    int physics;
    int chemistry;
    int total;

public:
    Student(int i, string n, int c, int p, int ch)
    {
        id = i;
        name = n;
        classNum = c;
        physics = p;
        chemistry = ch;
        total = p + ch;
    }
    int getTotal()
    {
        return total;
    }
    int getId()
    {
        return id;
    }
    void display()
    {
        cout << "学号：" << id << "；姓名：" << name << "；班级：" << classNum
             << "；物理成绩：" << physics << "；化学成绩：" << chemistry
             << "；总分：" << total << endl;
    }

    // 友元函数，比较两学生进行排序
    friend bool compareStudent(const Student &a, const Student &b);
};

// 比较函数
bool compareStudent(const Student &a, const Student &b)
{
    if (a.total != b.total)
        return a.total > b.total;
    else
        return a.id < b.id;
}

int main()
{
    Student students[] = {
        Student(20001, "张三", 1, 80, 85),
        Student(20002, "李四", 2, 82, 75),
        Student(20003, "王五", 3, 73, 68),
        Student(20004, "马六", 3, 85, 80),
        Student(20005, "陈七", 4, 90, 88)};
    int n = 5;
    sort(students, students + n, compareStudent);
    for (int i = 0; i < n; i++)
    {
        students[i].display();
    }

    return 0;
}