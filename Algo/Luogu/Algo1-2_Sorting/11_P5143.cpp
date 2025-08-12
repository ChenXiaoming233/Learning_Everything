#include <iostream>
#include <vector>
#include <algorithm>  
#include <cmath>
#include <iomanip>

using namespace std;


// 重载运算符控制排序， cout 控制输出的小数位数，使用 pow() 函数求幂，使用 sqrt() 函数开平方
struct Point{
    int x;
    int y;
    int z;
    bool operator<(const Point& other)const{
        return z < other.z;
    } // 重载运算符控制排序
};
/*
bool cmp(Point a, Point b){
    return a.z < b.z;
}
*/
int main() {
    int n; 
    double total = 0;
    cin >> n;
    vector<Point> points(n);
    for(int i = 0; i < n; i++){
        cin >> points[i].x >> points[i].y >> points[i].z;
    }
    sort(points.begin(), points.end());
    //sort(points.begin(), points.end(), cmp);
    for(int i = 0; i < n - 1 ; i++){
        total += sqrt(pow(points[i + 1].x - points[i].x, 2) + pow(points[i + 1].y - points[i].y, 2) + pow(points[i + 1].z - points[i].z, 2));
    }
    // 存在问题 不推荐使用
    // total = round(total * 1000) / 1000; // 利用 round 函数实现保留小数，total = round(total * 10^N) / 10^N，N 为保留位数
    cout<< fixed << setprecision(3) <<total;

    return 0;
}

