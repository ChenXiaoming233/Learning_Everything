// 暴力穷举
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int MaxSum = nums[0]; // 初始化为第一个元素
        for (int i = 0; i < nums.size(); i++)
        {
            int ThisSum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                ThisSum += nums[j];
                if (ThisSum > MaxSum)
                    MaxSum = ThisSum;
            }
        }
        return MaxSum;
    }
};
