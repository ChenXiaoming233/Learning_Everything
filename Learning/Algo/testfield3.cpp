#include <iostream>
#include <vector>
using namespace std;
void quickSort(int[], int, int);

int ans = 0;
int k = 0;

int main ()
{
    int n;
    cin >> n >> k;
    int nums1[n];
    for (int i = 0; i < n; ++i) {
        cin >> nums1[i];
    }
    quickSort(nums1, 0, n-1);
    cout << nums1[k];

    return 0;
}

void quickSort(int nums[], int left, int right){
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

