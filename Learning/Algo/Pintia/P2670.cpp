#include <iostream>
#include <vector>
#include <list>
#include <cmath>

using namespace std;
 
int main ()
{
    int f[2]={11,21};
    int a[25*2500];
    int pos = 0;
    char temp;
    while (1){
        cin >> temp;
        if (temp == 'E'){
            break;
        } 
        else if (temp == 'W'){
            a[pos++] = 1;
        }   
        else if (temp == 'L'){
            a[pos++] = 0;
        } 
    }    
        
        for (int mode = 0; mode < 2; mode++){
            int w=0, l=0;
            for (int i = 0; i < pos; i++){
                w += a[i];
                l += 1 - a[i];
                if (abs(w-l) >= 2 and max(w,l) >= f[mode]){
                    cout << w << ":" << l << endl;
                    w = l = 0;
                }
            }
            cout << w << ":" << l << endl;
            cout << endl;
        }
    


    return 0;
}