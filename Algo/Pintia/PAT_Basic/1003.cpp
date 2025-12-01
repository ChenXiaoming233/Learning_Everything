#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
 
int main ()
{
    vector<int> vec = {1,2,3};
    list<std::string> lst = {"A", "B", "C"};

    auto vec_it = find(vec.begin(), vec.end(), 2); // 在vector中查找
    auto lst_it = find(lst.begin(), lst.end(), "B"); // 在list中查找
    
    cout << *vec_it << " " << *lst_it;

    return 0;
}