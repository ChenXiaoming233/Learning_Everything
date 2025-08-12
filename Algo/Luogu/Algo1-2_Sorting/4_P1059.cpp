#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

//桶排序变体（去重需求 + 数据范围不大)
int main() {
    int n,count;
    bool book[1001] = {0};

    count = 0;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
        if(book[nums[i]] == 0){
            book[nums[i]] = 1;
        }
        else{
            count++;
        }
    }
    sort(nums.begin(),nums.end());
    int m = n - count;
    cout << m << endl;
    for(int i = 1; i <= 1000 ; i++){
        if(book[i] != 0){
            cout << i << " ";
        }
    }
    return 0;
}