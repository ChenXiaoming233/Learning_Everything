#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct coin{
    int m, v;
}a[110];

bool cmp(coin x, coin y){
    return x.v * y.m > y.v * x.m;
}

int main(){
    int n, t, c, i;
    float ans = 0;
    cin >> n >> t;
    c = t;
    for(int i = 0; i < n; i++){
        
    }
}