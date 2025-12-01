#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a = n / 100;     // 百位
    int b = n / 10 % 10; // 十位
    int c = n % 10;      // 个位

    for (int i = 0; i < a; i++)
        cout << "B";
    for (int i = 0; i < b; i++)
        cout << "S";
    for (int i = 1; i <= c; i++)
        cout << i;
    cout << endl;

    return 0;
}