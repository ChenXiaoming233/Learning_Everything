#include <algorithm>
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    string s = "hello";
    s.erase(1, 1);
    cout << s << endl;
    s.erase(s.find("l"), 1);
    cout << s << endl;
    return 0;
}