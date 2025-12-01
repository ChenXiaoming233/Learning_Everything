#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    if(a + b < 0)
        cout << '-';
    string c_str = to_string(abs(a + b));
    int rest = c_str.size() % 3 == 0 ? 3 : c_str.size() % 3;
    cout << c_str.substr(0, rest);
    for(int i = rest; i < c_str.size(); i += 3){
        cout << "," << c_str.substr(i, 3);
    }
    return 0;
} 