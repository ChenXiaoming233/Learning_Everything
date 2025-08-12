#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int quickSelect(int nums[], int left, int right, int k) {
    while (left <= right) {
        if (left == right) {
            return nums[left];
        }
        
        // 选择枢轴（这里使用三数取中法）
        int mid = left + (right - left) / 2;
        if (nums[left] > nums[right]) swap(nums[left], nums[right]);
        if (nums[mid] > nums[right]) swap(nums[mid], nums[right]);
        if (nums[mid] > nums[left]) swap(nums[mid], nums[left]);
        int pivot = nums[left];
        
        int i = left, j = right;
        while (i <= j) {
            while (nums[i] < pivot) i++;
            while (nums[j] > pivot) j--;
            if (i <= j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        
        // 只处理包含第k个元素的区间
        if (k <= j) {
            right = j;
        } else if (k >= i) {
            left = i;
        } else {
            return nums[k];
        }
    }
    return nums[k];
}

int main() {

    //Blackmagic
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    int* nums = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    int result = quickSelect(nums, 0, n - 1, k);
    cout << result;
    
    delete[] nums;
    return 0;
}