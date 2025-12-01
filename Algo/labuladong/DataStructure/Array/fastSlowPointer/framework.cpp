// 快慢指针
// #原地修改数组/指针 ~~#滑动窗口~~
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

class Solution // 数组
{ 
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        int slow = 0, fast = 0;
        while (fast < nums.size())
        {
            if (nums[fast] != nums[slow])
            {
                slow++;
                nums[slow] = nums[fast];   
            }
            // ! 注意 如果先令 fast++ 则会导致越界并且第一个元素被跳过
            fast++; 
        }
        // 数组长度为索引 + 1
        return slow + 1;
    }
};

class Solution2 // 链表
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast != nullptr)
        {
            if (fast->val != slow->val)
            {
                // nums[slow] = nums[fast];
                slow->next = fast;
                // slow++;
                slow = slow->next;
            }
            fast = fast->next;
        }
        // 断开与后面重复元素的连接
        slow->next = nullptr;
        return head;
    }
};