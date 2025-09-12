#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums1 = {3, 1, 3, 4, 5};
    
    for (int i = 1; i < nums1.size(); i++) {
        int base = nums1[i];
        int j = i - 1; 
        while (j >= 0 and nums1[j] > base) {  
            nums1[j + 1] = nums1[j];
            j--;
        }
        nums1[j + 1] = base;
    }
    
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }
    
    return 0;
}