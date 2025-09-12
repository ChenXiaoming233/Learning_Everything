#include <iostream>
#include <vector>
using namespace std;

int dfs(vector<int> &nums, int target, int i, int j){
    if(i > j){
        return -1;
    }
    int m = (i + j) / 2;
    if(nums[m] < target){
        return dfs(nums, target, m + 1, j);
    }
    if(nums[m] > target){
        return dfs(nums, target, i, m-1);
    }
    else{
        return m;
    }
}

int main() {
    vector<int> nums = {1, 3, 6 ,8 ,12 ,15};
    int size = nums.size();
    int place = dfs(nums, 6, 0, size - 1);
    cout << place;
    return 0;
}