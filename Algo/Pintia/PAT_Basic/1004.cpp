#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Student
{
    string name;
    string num;
    int score;
} s[1000];

bool cmp(Student a, Student b)
{
    if (a.score != b.score)
        return a.score > b.score;
    return a.num < b.num;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i].name >> s[i].num >> s[i].score;
    }
    sort(s + 1, s + n + 1, cmp);
    cout << s[1].name << " " << s[1].num << endl;
    cout << s[n].name << " " << s[n].num << endl;
    return 0;
}