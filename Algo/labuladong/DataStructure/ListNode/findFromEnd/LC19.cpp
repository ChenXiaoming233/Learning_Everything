// LC19 - 删除链表的倒数第 N 个结点

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummy(0);
        dummy.next = head;
        // 删除倒数第 n 个，需要先找到倒数第 n + 1 个
        // 由虚拟头节点防止溢出
        ListNode *x = findFromEnd(head, n + 1);
        x->next = x->next->next;
        return dummy.next;
    }

private:
    ListNode *findFromEnd(ListNode *head, int n)
    {
        ListNode *p1 = head;
        for (int i = 0; i < n; i++)
        {
            p1 = p1->next;
        }
        ListNode *p2 = head;
        while (p1 != nullptr)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};