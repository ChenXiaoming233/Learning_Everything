#include <iostream>
#include <vector>
using namespace std;
int medianThree(vector<int>&,int,int);
int partition(vector<int>&, int, int);
void quickSort(vector<int>&, int, int);
void insertSort(vector<int>&, int, int);

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    vector<int> nums1(n);
    for(int i = 0; i < n; i++){
        cin >> nums1[i];
    }
    int left = 0;
    int right = n-1;
    quickSort(nums1, left, right);
    for(int i = 0; i < n; i++){
        if(i < n - 1){
            cout << nums1[i] << " ";
        }
        else{
            cout << nums1[i];
        }
    }
    return 0;
}

int medianThree(vector<int>&nums, int left, int right){
        int mid = (left+right)/2;
        int l = nums[left], r = nums[right], m = nums[mid];
        
        if ((l < m and m < r)or(r < m and m < l)){
            return mid;
        }
        if ((m < l and l < r)or(r < l and l < m)){
            return left;
        }
        else {
            return right;
        }
    }   

int partition(vector<int>&nums, int left, int right){
    int med = medianThree(nums, left, right);
    int i = left;
    int j = right;
    swap(nums[left],nums[med]);
    while (i < j){
        while ((i < j)and(nums[j] >= nums[left])){
            j--;
        }
        while((i < j)and(nums[i] <= nums[left])){
            i++;
        }
        swap(nums[i],nums[j]);
    }
    swap(nums[i],nums[left]);
    return i;
}

void insertSort(vector<int>&nums, int left, int right){
    for(int i = left + 1; i <= right; i++){
        int base = nums[i];
        int j = i - 1;
        while(j >=left and nums[j] > base){
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = base;
    }
}

void quickSort(vector<int>&nums, int left, int right){
    while(right - left > 16){
        int pivot = partition(nums, left, right);
        if ((pivot - left) < (right - pivot)){
            quickSort(nums, left, pivot - 1);
            left = pivot + 1;
        }
        else {
            quickSort(nums, pivot + 1, right);
            right = pivot - 1;
        }
    } 
    insertSort(nums,left,right);
    return;
}