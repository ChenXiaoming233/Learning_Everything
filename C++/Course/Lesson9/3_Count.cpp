#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Student
{
    string name;
    double en;
    double phy;
    double math;
    double chem;
    double total;
};

bool compareByTotal(const Student &a, const Student &b)
{
    return a.total > b.total;
}

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
        Student s = {name, en, phy, math, chem, 0};
        s.total = s.en + s.phy + s.math + s.chem;
        students.push_back(s);
    }
    infile.close();

    sort(students.begin(), students.end(), compareByTotal);

    cout << "按总分从高到低排序结果如下：" << endl;
    cout << "姓名\t英语\t物理\t高数\t化学\t总分" << endl;
    for (int i = 0; i < students.size(); i++)
    {
        cout << students[i].name << "\t"
             << students[i].en << "\t"
             << students[i].phy << "\t"
             << students[i].math << "\t"
             << students[i].chem << "\t"
             << students[i].total << endl;
    }
    return 0;
}