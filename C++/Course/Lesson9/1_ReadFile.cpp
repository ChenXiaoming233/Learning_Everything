#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Student
{
    string name;
    double en;
    double phy;
    double math;
    double chem;
};

int main()
{
    // 读取文件
    ifstream infile("scores.txt");

    string header; // 读取文件头部并去除
    getline(infile, header);

    vector<Student> students;
    string name;
    double en, phy, math, chem;
    while (infile >> name >> en >> phy >> math >> chem)
    {
        Student s = {name, en, phy, math, chem};
        students.push_back(s);
    }
    infile.close();

    // 查询成绩
    string name2;
    cout << "请输入学生姓名: ";
    cin >> name2;
    bool found = false;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].name == name) {
            cout << students[i].name << "的成绩：" << endl;
            cout << "英语: " << students[i].en << endl;
            cout << "物理: " << students[i].phy << endl;
            cout << "高数: " << students[i].math << endl;
            cout << "化学: " << students[i].chem << endl;
            found = true;
            break;
        }
    }
    if (!found) 
        cout << "未找到" << endl;
    return 0;
}