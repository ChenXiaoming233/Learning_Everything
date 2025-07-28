#include <iostream>
 
using namespace std;
 
int main ()
{
    float m,h;
    cin >> m >> h;
    float bmi;
    bmi = m/(h*h);
    if(bmi<18.5){
        cout << "Underweight";
    }
    if(bmi>=18.5 and bmi <24){
        cout << "Normal";
    }
    if(bmi>=24){
        cout << bmi << endl << "Overweight";
    }
    return 0;
}