// #模拟 #暴力 #数论基础
// 题解：https://www.cnblogs.com/cmmdc/p/6729680.html

/*
根据N的值的取值范围小于等于2的31次方，而这个值介于12的阶乘到13的阶乘之间，所以我们可以得到最大的值应该是12个数连续相乘，又因为1不计算在内，所以最多只要有11为连续因子即可。
采用暴力的思想，我们让他分别从2、3、4...sqrt(N)开始乘，连着乘11位、10位...1位。
*/

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    // limit 是外层循环的上限，即 sqrt(N)
    // 解释：如果连续因子长度至少为2，假设为 i * (i+1) <= n
    // 那么 i^2 < n，所以 i < sqrt(n)
    long long limit = sqrt(n) + 1;

    int max_len = 0;         // 最长连续因子的长度
    long long first_num = 0; // 最长序列的起始数字

    // 从 2 开始枚举起始因子
    for (long long i = 2; i <= limit; i++)
    {
        long long current_product = 1;
        long long j = i;

        // 内层循环：尝试向后连乘
        while (true)
        {
            current_product *= j;

            if (current_product > n)
                break; // 剪枝 + 防溢出

            // 关键判断：必须是“当前连乘积”能整除 N
            // e.g. i = 5 时，630 / 5 = 126, 可以继续令 i++ 尝试 630/5/6, 并记录每次尝试的长度... i = 8 时, 5 * 6 * 7 * 8 = 1680 > 630 被剪枝
            if (n % current_product == 0)
            {
                int current_len = j - i + 1; // 当前序列长度
                if (current_len > max_len)
                {
                    max_len = current_len;
                    first_num = i;
                }
            }
            else
            {
                // 不能整除，序列中断
                break;
            }
            j++;
        }
    }

    // 输出结果
    if (max_len == 0)
    {
        // 如果没有找到连续因子（通常 N 是素数），输出 N 本身
        cout << 1 << endl;
        cout << n << endl;
    }
    else
    {
        cout << max_len << endl;
        for (int k = 0; k < max_len; k++)
        {
            if (k > 0)
                cout << "*";
            cout << first_num + k;
        }
        cout << endl;
    }

    return 0;
}