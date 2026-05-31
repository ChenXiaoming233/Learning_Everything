#include <iostream>
#include <list>
using namespace std;

int main()
{   
    // 创建列表
    list<double> l1 = {3.14, 1.59, 2.65, 0.78};

    // 插入元素
    list<double>::iterator it = l1.begin();
    for (int i = 0; i < 2; i++) 
       it++;  
    l1.insert(it, 5.20); 

    // 升序排序
    l1.sort();

    // 输出列表
    cout << "List: ";
    for (list<double>::iterator it = l1.begin(); it != l1.end(); it++)
        cout << *it << " ";
        
    return 0;
}