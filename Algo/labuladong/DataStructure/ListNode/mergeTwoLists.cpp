// 合并两个有序链表
// #虚拟头节点：需要创造一条新链表的时候，可以使用虚拟头结点简化边界情况的处理

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        // dummy 为虚拟头结点，避免额外处理空指针的情况；需要创造一条新链表的时候，可以使用虚拟头结点简化边界情况的处理
        ListNode dummy(-1); 
        ListNode *p = &dummy;
        ListNode *p1 = l1, *p2 = l2; // l1 l2 为指向两链表首元素的指针

        while (p1 != nullptr && p2 != nullptr)
        {
            if (p1->val > p2->val)
            {
                p->next = p2;
                p2 = p2->next;
            }
            else
            {
                p->next = p1;
                p1 = p1->next;
            }
            // ! 注意 不要忘记令 p 指针不断前进
            p = p->next;
        }

        // 将剩余链表直接接入后方
        if (p1 != nullptr)
        {
            p->next = p1;
        }
        if (p2 != nullptr)
        {
            p->next = p2;
        }
        // 返回合并后链表的第一个节点；dummy 为虚拟头节点，应返回下一节点；dummy 为对象，不应写 dummy->next
        return dummy.next;
    }
};