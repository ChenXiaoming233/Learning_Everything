#include<iostream>
#include<cstdint> // 添加此行以包含 定宽整数 的定义
#include<cstdio> // 添加此行以包含 printf 函数的定义
#include<algorithm>

using namespace std;

struct book{
        string title;
        char author;
        float value;
    };
struct book library;

int main() {
    
    book a;
    a.title = "Cpp Learning";
    library.title = "C Learning";
    
    struct languages {
        string name;
        int year;
        char level;
    }python={
        "Python",
        1991,
        'A'
    }, cpp={
        "C++",
        1985,
        'A'
    };

    struct University {
        string name;
        int rank;
        char level;
    } THU {
        "TsinghuaUniversity",
    }, FZU {
        "FuzhouUniversity",
    };
    


    cout << a.title << library.title << endl;
    cout << python.name << python.year << python.level << endl;
    cout << cpp.name << cpp.year << cpp.level << endl;
    cout << THU.name << FZU.name << endl;
    return 0;
}