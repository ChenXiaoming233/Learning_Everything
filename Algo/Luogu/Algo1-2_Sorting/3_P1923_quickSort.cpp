#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

int medianThree(vector<int>& nums, int left, int right) {
    int mid = (left + right) / 2;
    int l = nums[left];
    int m = nums[mid];
    int r = nums[right];
    if ((l < m && m < r) || (r < m && m < l)) {
        return mid;
    }
    else if ((m < l && l < r) || (r < l && l < m)) {
        return left;
    }
    else {
        return right;
    }
}

int partition(vector<int>& nums, int left, int right) {
    int med = medianThree(nums, left, right);
    swap(nums[med], nums[left]);
    int i = left;
    int j = right;
    while (i < j) {
        while (i < j && nums[j] >= nums[left]) {
            j--;
        }
        while (i < j && nums[i] <= nums[left]) {
            i++;
        }
        swap(nums[i], nums[j]);
    }
    swap(nums[left], nums[i]);
    return i;
}

void quickSort(vector<int>& nums, int left, int right) {
    while (left < right) {
        int pivot = partition(nums, left, right);
        if (pivot - left < right - pivot) {
            quickSort(nums, left, pivot - 1);
            left = pivot + 1;
        }
        else {
            quickSort(nums, pivot + 1, right);
            right = pivot - 1;
        }
    }
}

int main() {
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
        }
        else {
            cout << nums[i];
        }
    }
    return 0;
}