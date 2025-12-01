// LeetCode27 - 移动零
// #原地修改数组/指针
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    void moveZeroes(vector<int>& nums){
        if(nums.size() == 0){
            return;
        }
        int slow = 0, fast = 0;
        while(fast < nums.size()){
            if(nums[fast] != 0){
                nums[slow] = nums[fast];
                slow++;
            }
            fast ++;
        }
        for(int i = slow; i < nums.size(); i++){
            nums[i] = 0;
        } 
        return;
    } 
};