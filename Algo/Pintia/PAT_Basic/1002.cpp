#include <iostream>
#include <string>
 
using namespace std;
 
int main ()
{
    string num;
    int sum = 0;
    cin >> num;
    for(int i=0; i<num.size(); i++){
        sum = num[i] + sum - '0';
    }
    string sumstr;
    sumstr = to_string(sum);

    for(int i=0; i<sumstr.size(); i++){
        if(sumstr.at(i) == '1'){
            cout << "yi";
        }
        if(sumstr.at(i) == '2'){
            cout << "er";
        }
        if(sumstr.at(i) == '3'){
            cout << "san";
        }
        if(sumstr.at(i) == '4'){
            cout << "si";
        }
        if(sumstr.at(i) == '5'){
            cout << "wu";
        }
        if(sumstr.at(i) == '6'){
            cout << "liu";
        }
        if(sumstr.at(i) == '7'){
            cout << "qi";
        }
        if(sumstr.at(i) == '8'){
            cout << "ba";
        }
        if(sumstr.at(i) == '9'){
            cout << "jiu";
        }
        if(sumstr.at(i) == '0'){
            cout << "ling";
        }
        if (i != sumstr.size() - 1) {  
            std::cout << " ";
        }
    }
    return 0;
}