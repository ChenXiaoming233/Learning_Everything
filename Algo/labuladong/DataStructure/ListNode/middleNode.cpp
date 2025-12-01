// 单链表的中点

#include <bits/stdc++.h>

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

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        if (head == nullptr) // 检查是否空指针！
        {
            return nullptr;
        }
        // 快慢指针初始化指向 head
        ListNode *slow = head;
        ListNode *fast = head;
        
        // ! 注意 快指针走两步，必须先保证 “走第一步 fast->next” 是合法的；
        while (fast != nullptr && fast->next != nullptr) 
        {
            // 慢指针走一步，快指针走两步
            slow = slow->next;
            fast = fast->next->next;
        }
        // 慢指针指向中点
        // 如果链表长度为偶数（中点有两个时），返回的节点是 **靠后** 的节点
        return slow;
    }
};

