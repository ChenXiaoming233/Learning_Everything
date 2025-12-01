// Kadane算法
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ThisSum = nums[0], MaxSum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            ThisSum = max(nums[i], ThisSum + nums[i]);
            MaxSum = max(MaxSum, ThisSum);
        }
        return MaxSum;
    }
};
