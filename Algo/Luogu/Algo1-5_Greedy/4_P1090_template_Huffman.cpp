#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n, n2 = 0, a1[10010], a2[10010], sum = 0;
int main()
{
    cin >> n;
    memset(a1, 127, sizeof(a1));
    memset(a2, 127, sizeof(a2));
    for (int i = 0; i < n; i++)
    {
        cin >> a1[i];
    }
    sort(a1, a1 + n);
    int i = 0, j = 0, k, w;
    for (k = 1; k < n; k++)                     // n 堆需要合并 n - 1 次
    {                                           // 双序列归并
        w = a1[i] < a2[j] ? a1[i++] : a2[j++];  // 选择两数列最小堆，若 a1[i] 较小，先将其赋值再自增，**若 ++i 则先自增再赋值**
        w += a1[i] < a2[j] ? a1[i++] : a2[j++]; // 再次选择最小堆与前者合并
        a2[n2++] = w;                           // n2 指向 a2 中的下一个空闲位置
        sum += w;
    }
    cout << sum;
}