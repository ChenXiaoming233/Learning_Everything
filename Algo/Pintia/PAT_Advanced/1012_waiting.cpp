// map哈希表 pair自定义结构体

#include <bits/stdc++.h>

using namespace std;

struct Stu{
    int no;
    int c;
    int m;
    int e;
    float avg;
    int best_sort;
    char best_class;
}stus[2020];

int waitlist[2020];
int n, m;

int main(){ 
    int n, m; // 总数 待查询数量
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> stus[i].no >> stus[i].c >> stus[i].m >> stus[i].e;
        stus[i].avg = static_cast<float>(stus[i].c + stus[i].m + stus[i].e) / 3;
    }
    for(int i = 0; i < m; i++){
        cin >> waitlist[i];
    }
    bool cmp(int a, int b)
        return a > b;
}