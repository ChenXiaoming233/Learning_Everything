#include <iostream>
#include <string>
using namespace std;

// 抽象基类
class Employee
{
private:
    string name;
    string id;

public:
    Employee(string n, string i) : name(n), id(i) {}
    virtual ~Employee() {}

    string getName()
    {
        return name;
    }
    string getId()
    {
        return id;
    }

    virtual double getSalary() = 0; // 计算薪资
    virtual void print() = 0;       // 输出信息
};

// 正式员工类
class SalariedEmp : public Employee
{
private:
    double permonth;

public:
    SalariedEmp(string n, string i, double s) : Employee(n, i), permonth(s) {}

    double getSalary()
    {
        return permonth;
    }

    void print()
    {
        cout << "正式员工信息" << endl;
        cout << "姓名：" << getName() << " 工号：" << getId() << " 本月薪资：" << getSalary() << endl;
    }
};

// 兼职员工类
class PartTimeEmp : public Employee
{
private:
    double perhour;
    double time;

public:
    PartTimeEmp(string n, string i, double s, double h) : Employee(n, i), perhour(s), time(h) {}

    double getSalary()
    {
        return perhour * time;
    }

    void print()
    {
        cout << "兼职员工信息" << endl;
        cout << "姓名：" << getName() << " 工号：" << getId() << " 本月薪资：" << getSalary() << endl;
    }
};

int main()
{
    string n, id;
    double s, r, t;

    // 正式员工
    cin >> n >> id >> s;
    SalariedEmp emp1(n, id, s);

    // 兼职员工
    cin >> n >> id >> r >> t;
    PartTimeEmp emp2(n, id, r, t);

    Employee *ptr1 = &emp1;
    Employee *ptr2 = &emp2;

    ptr1->print();
    ptr2->print();

    return 0;
}