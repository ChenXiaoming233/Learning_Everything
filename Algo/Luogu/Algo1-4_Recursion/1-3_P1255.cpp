#include <iostream>
#define maxn 10000

using namespace std;

struct Bigint{
    int len = 0;
    int a[maxn] = {0};
    Bigint(int x = 0){
        do{
            a[len] = x % 10;
            x /= 10;
            len++;
        }while(x > 0);
    }
    int &operator[](int i){
        return a[i];
    }
    void flatten(int L){
        len = L;
        for(int i = 1; i <= len; i++){
            a[i + 1] = a[i] / 10;
            a[i] %= 10;
        }
        while(len > 1 and a[len] == 0){
            len--;
        }
    }
    void print(){
        for(int i = 1; i <= len; i++){
            cout << a[i];
        }
    }
};

Bigint operator+(Bigint a, Bigint b){
    Bigint c;
    int len = max(a.len, b.len);
    for(int i = 1; i <= len; i++){
        c[i] = a[i] + b[i];
    }
    c.flatten(len + 1);
    return c;
}

Bigint operator*(Bigint a, int b){
    Bigint c;
    int len = a.len;
    for(int i = 1; i <= len; i++){
        c[i] = a[i] * b;
    }
    c.flatten(len + 11);
    return c;
}

int main()
{
    Bigint ans(0), fac(1);
    int m;
    cin >> m;
    for(int i = 1; i <=m; i++){
        fac = fac * i;
        ans = ans + fac;
    }
    ans.print();
    return 0;
}