#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

// 列车排序过程类似冒泡排序
int main() {
    vector<int> nums = {3,2,1,3,4,5,6};
    for(int i = 0; i < nums.size() - 1; i++){
        for(int j = 0; j < nums.size() - i - 1; j++){
            if(nums[j] > nums [j + 1]){
                swap(nums[j], nums [j + 1]);
            }
        }
    }
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i];
    }
    return 0;
}