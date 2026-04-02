#include <iostream>
using namespace std;

/* 我在此处补充代码 */
class Student
{
private:
    int score;
    static int total;
    static int count;

public:
    Student(int s) // 构造函数
    {
        score = s;
        total += s;
        count++;
    }

    static double getAvgScore() // 求平均成绩
    {
        if (count == 0)
            return 0;
        return (double)total / count;
    }
};

int Student::total = 0;
int Student::count = 0;

int main()
{
    Student s1(90);
    Student s2(80);
    Student s3(70);
    Student s4(60);
    cout << "平均成绩为：" << Student::getAvgScore() << endl;
    return 0;
}