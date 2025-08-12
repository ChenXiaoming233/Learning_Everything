#include <iostream>
#include <vector>
#include <algorithm>  // 用于std::swap
#include <cstdlib>    // 用于rand()

using namespace std;

void insertionSort(vector<int>& nums, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = nums[i];
        int j = i - 1;
        while (j >= left && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}

void quickSort(vector<int>& nums, int left, int right) {
    while (right - left > 16) {
        // 随机选择pivot
        int pivotIdx = left + rand() % (right - left + 1);
        swap(nums[pivotIdx], nums[left]);
        
        // 三路划分
        int pivot = nums[left];
        int lt = left;
        int gt = right;
        int i = left + 1;
        
        while (i <= gt) {
            if (nums[i] < pivot) {
                swap(nums[i++], nums[lt++]);
            } else if (nums[i] > pivot) {
                swap(nums[i], nums[gt--]);
            } else {
                i++;
            }
        }
        
        // 递归处理较小的部分
        if (lt - left < right - gt) {
            quickSort(nums, left, lt - 1);
            left = gt + 1;
        } else {
            quickSort(nums, gt + 1, right);
            right = lt - 1;
        }
    }
    
    // 对小数组使用插入排序
    insertionSort(nums, left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    srand(time(nullptr));  // 初始化随机数种子
    
    int n = 0;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    quickSort(nums, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            cout << nums[i] << " ";
        } else {
            cout << nums[i];
        }
    }
    
    return 0;
}