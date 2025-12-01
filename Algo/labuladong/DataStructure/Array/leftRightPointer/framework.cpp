// 左右指针
// #二分查找 ~~#n数之和~~ #反转数组 ~~#回文串判断~~
#include <vector>
using namespace std;

// 二分查找
// std::lowerbound() std::upperbound()
int binarySearch(vector<int> &nums, int target)
{
    // 一左一右两个指针相向而行
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (right + left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid - 1;
    }
    return -1;
}

// 反转数组
// std::reverse(v.begin(), v.end())
void reverseString(vector<char> &s)
{
    // 一左一右两个指针相向而行
    int left = 0, right = s.size() - 1;
    while (left < right)
    {
        // 交换 s[left] 和 s[right]
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}