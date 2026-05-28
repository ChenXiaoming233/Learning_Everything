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

// 读取文件
vector<Student> read(string &filename)
{
    vector<Student> students;
    ifstream inFile(filename);
    // 读取文件头部并去除
    string header;
    getline(inFile, header);
    string name;
    double eng, phy, math, chem;
    while (inFile >> name >> eng >> phy >> math >> chem)
    {
        Student s = {name, eng, phy, math, chem};
        students.push_back(s);
    }
    inFile.close();
    return students;
}

// 追加条目
void append(const string &filename, Student &s)
{
    ofstream outFile(filename, ios::app);
    outFile << s.name << " " << s.en << " " << s.phy << " " << s.math << " " << s.chem << endl;
    outFile.close();
}

// 输入学生
void addStudent(const string &filename, vector<Student> &students)
{
    Student newS;
    cout << "请输入学生姓名：";
    cin >> newS.name;
    cout << "请输入英语成绩：";
    cin >> newS.en;
    cout << "请输入物理成绩：";
    cin >> newS.phy;
    cout << "请输入高数成绩：";
    cin >> newS.math;
    cout << "请输入化学成绩：";
    cin >> newS.chem;

    append(filename, newS);
    students.push_back(newS);
    cout << "已保存" << endl;
}

// 查询成绩
void search(vector<Student> &students)
{
    string name;
    cout << "请输入要查询的学生姓名：";
    cin >> name;
    bool found = false;
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].name == name)
        {
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
}

int main()
{
    string filename = "scores.txt";
    vector<Student> students = read(filename);
    int choice;
    while (1)
    {
        cout << "1. 查询学生成绩" << endl;
        cout << "2. 添加新学生" << endl;
        cout << "3. 退出" << endl;
        cout << "请选择：";
        cin >> choice;
        switch (choice)
        {
        case 1:
            search(students);
            break;
        case 2:
            addStudent(filename, students);
            break;
        case 3:
            cout << "程序退出。" << endl;
            break;
        }
    }
    return 0;
}