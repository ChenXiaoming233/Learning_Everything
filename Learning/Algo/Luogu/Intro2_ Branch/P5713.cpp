#include <iostream>
 
using namespace std;
 
int main ()
{
    int n=0;
    int time1,time2;
    time1=0;
    time2=0;
    cin >> n;
    time1=5*n;
    time2=3*n+11;
    if(time1<time2){
        cout << "Local";
    }
    else{
        cout << "Luogu";
    }
    return 0;
}