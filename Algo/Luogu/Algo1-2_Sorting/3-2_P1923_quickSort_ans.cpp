#include <iostream>
#include <vector>
using namespace std;
void quickSort(vector<int>&, int, int);

int ans = 0;
int k = 0;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n >> k;
    vector<int>nums1(n);
    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }
    quickSort(nums1, 0, nums1.size()-1);
    cout << nums1[k];
    return 0;
}

void quickSort(vector<int>&nums, int left, int right){
    if(left == right){
        ans = nums[left];
        return;
    }
    int i = left , j = right;
    int flag = nums[(left+right)/2];
    do{
        while(nums[i] < flag){
            i++;
        }
        while(nums[j] > flag){
            j--;
        }
        if (i <= j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }while(i <= j);  
    // i与j先移动后判断，则最后一次移动会令 i > j（但不进行交换），此时数组被划分为 left - j - i - right，分别小于/等于/大于 flag

    if(k <= j){
        quickSort(nums, left, j);
    }
    else if(i <= k){
        quickSort(nums, i, right);
    }
    else{
        quickSort(nums, j+1, i-1);
    }
}

