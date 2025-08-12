#include <iostream>
 
using namespace std;
 
int main ()
{
    int y,m;
    cin >> y >> m;
    if(m%2==1 and m>=1 and m<=7){
        cout << "31";
    }
    if(m%2==0 and m>=3 and m<=7){
        cout << "30";
    }
    if(m%2==0 and m>=8 and m<=12){
        cout << "31";
    }
    if(m%2==1 and m>=8 and m<=12){
        cout << "30";
    }    
    if(m==2 and y%4!=0){
        cout << "28";
    }
    if(m==2 and y%4==0){
        if(y%400==0){
            cout << "29";
        }
        else{
            if(y%100==0){
                cout << "28";
            }
            else{
                cout << "29";
            }
        }
        
    }
    return 0;
}