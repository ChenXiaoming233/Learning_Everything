#include <iostream>
#include <vector>
#include <algorithm>  
#include <cmath>

using namespace std;


int main() {
    int num;
    bool jolly = true;
    cin >> num;
    vector<int> nums(num);
    vector<int> diff(num - 1);
    for(int i = 0; i < num; i++){
        cin >> nums[i];
    }

    for(int i = 0; i < num - 1; i++){
        diff[i] = abs(nums[i + 1] - nums[i]);
    }
    sort(diff.begin(),diff.end());
    for(int i = 0; i < num - 2; i++){
        if(diff[i + 1] - diff[i] != 1){
            cout << "Not jolly";
            jolly = false;
            break;
        }
        else{
            continue;
        }
    }
    if(jolly == true){
        cout << "Jolly";
    }

    return 0;
}