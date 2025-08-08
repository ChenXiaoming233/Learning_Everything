#include <iostream>
#include <vector>
#include <algorithm>  
#include <cmath>
#include <iomanip>

using namespace std;

struct Birthday{
    string s;
    int no;
    int y;
    int m;
    int d;
    bool operator<(const Birthday &other)const{
        if(y != other.y){
            return y < other.y;
        }
        if(m != other.m){
            return m < other.m;
        }
        if(d != other.d){
            return d < other.d;
        }
        return no > other.no;
    }

};

int main() {
    int n; 
    double total = 0;
    cin >> n;
    vector<Birthday> days(n);
    for(int i = 0; i < n; i++){
        cin >> days[i].s >> days[i].y >> days[i].m >> days[i].d;
        days[i].no = i;
    }
    sort(days.begin(), days.end());
    for(int i = 0; i < n; i++){
        cout << days[i].s << endl;    
    }
    return 0;
}


