#include <iostream>
#define maxn 10000

using namespace std;

struct Bigint{
    int len = 0, a[maxn];
    Bigint(int x = 0){ // x 作为输入参数，初始化为0
        memset(a, 0 , sizeof(a)); 
        for(int len = 1; x; len++){ // 最后一次 x 被
            a[len] = x % 10;
            x /= 10;
        }
        len--;
    }
    int &operator[](int i){
        return a[i];
    }
    void flatten(int L){
        len = L;
        for(int i = max(len, 1); i >= 1; i--){
            a[len + 1] += a[len] / 10;
            a[len] %= 10;
        }
        for(int i = 1; i <= maxn; i++){
            if(a[i] == 0){
                len--;
            }
        }
    }
    void print(){
        for(int i = 1; i <= maxn; i++){
            cout << a[i];
        }
    }
};

Bigint operator+(Bigint a, Bigint b)
{
    Bigint c;
    int len = max(a.len, b.len);
    for (int i = 1; i <= len; i++)
    {
        c[i] += a[i] + b[i];
    }
    c.flatten(len + 1); // 答案不超过 len + 1 位数
    return c;
}

Bigint operator*(Bigint a, int b)
{
    Bigint c;
    int len = a.len;
    for (int i = 1; i <= len; i++)
    {
        c[i] = a[i] * b;
    }
    c.flatten(len + 11); // int 类型最长能存储 10 位数，c 最多比 a 长 11 位数
    return c;
}

int main()
{
    int a;
    
}