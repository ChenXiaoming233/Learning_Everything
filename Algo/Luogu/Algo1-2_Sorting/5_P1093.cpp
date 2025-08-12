#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

//结构体（单对象多参数）+ sort 排序与 cmp 函数使用
struct stu{
        int num;
        int c,m,e;
        int sum;
    }student[310];

bool cmp(const stu& a, const stu& b) {
    if(a.sum != b.sum) {
        return a.sum > b.sum;  // sum 降序
    }
    if(a.c != b.c) {
        return a.c > b.c;      // c 降序
    }
        return a.num < b.num;      // num 升序
}//对结构体排序 cmp 需要考虑所有情形，依据 sum 排序后若 sum 相等则依据 c 排序，若 c 相等则依据 num 排序

int main() {
    int num = 0;
    cin >> num;
    for(int i = 1; i <= num; i++){
        student[i].num=i;
        cin >> student[i].c >> student[i].m >> student[i].e;
        student[i].sum =  student[i].c + student[i].m + student[i].e;
    }
    sort(student+1,student+num+1,cmp);
    for(int i = 1; i <= 5; i++){
        cout << student[i].num << " " << student[i].sum << endl;
    }
    return 0;
}