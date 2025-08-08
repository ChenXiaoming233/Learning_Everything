#include <iostream>
#include <vector>
#include <algorithm>  
#include <cmath>
#include <iomanip>

using namespace std;

// debug开不出来 服了 通过补0进行排序也是不必要的 但是至今我们也不知道bug卡哪了
struct Num{
    int no;
    string num;
};

bool cmp(Num nums1, Num nums2){
    return nums1.num > nums2.num;
}

void paddingZero(vector<Num>& nums, vector<Num>& nums2){
    int maxLength = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i].num.length() > maxLength){
            maxLength = nums[i].num.length();
        }
    }
    for(int i = 0; i < nums.size(); i++){
        if(nums[i].num.length() < maxLength){
            nums2[i].num = nums[i].num;
            nums2[i].num.append(maxLength - nums[i].num.length(),'0');
        }
        else{
            nums2[i].num = nums[i].num;
        }
    }
    
}


int main() {
    int n; 
    cin >> n;
    vector<Num> nums(n);
    vector<Num> nums2(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i].num;
        nums[i].no = i;
        nums2[i].no = i;
    }
    paddingZero(nums,nums2);
    sort(nums2.begin(), nums2.end(),cmp);
    for(int i = 0; i < n; i++){
        int j = nums2[i].no;
        cout << nums[j].num;
    }
    return 0;
}


