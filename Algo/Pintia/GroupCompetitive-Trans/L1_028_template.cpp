// #数论 - 判断素数
#include <bits/stdc++.h>

using namespace std;

bool isValid(int n){
    int sq = sqrt(n);
    // ! 注意 特判 n <= 1
    if(n <= 1) return 0;
    for(int i = 2; i < sq; i++){
        if(n % i == 0)
            return 0;
    }
    return 1;
}


int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(isValid(num) == true)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

}