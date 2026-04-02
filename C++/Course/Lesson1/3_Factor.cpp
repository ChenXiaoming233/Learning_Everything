#include <iostream>
using namespace std;

int main()
{
    int num = 0;
    cin >> num;
    if (num == 0)
        cout << "0 是没有因子的";
    else if (num < 0)
        cout << "这太小了";
    else
        for (int i = 1; i <= num; i++)
            if (num % i == 0)
                cout << i << " ";
    return 0;
}