#include <iostream>
#define maxn 10000

using namespace std;

struct Bigint{
    int len = 0, a[maxn];
    Bigint(int x = 0){
        memset(a, 0 , sizeof(a));
        for(int len = 1; x; len++){
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

int main()
{
    int a;
    
}