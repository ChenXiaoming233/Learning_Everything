#include<iostream>
#include<cstdint>
#include<cstdio> 
#include<algorithm>
 
using namespace std;


int main() {
    int x;
    cin >> x;
    if (x==0){
        cout << "Today, I ate 0 apple.";
    }
    if (x==1){
        cout << "Today, I ate 1 apple.";
    }
    if (x>1){
        cout << "Today, I ate " <<x<< " apples.";
    }

}
