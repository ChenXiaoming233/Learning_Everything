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

ListNode *partition(ListNode *l1, int x)
{
    ListNode dummy1(0);
    ListNode dummy2(0);
    ListNode *cur1 = &dummy1;
    ListNode *cur2 = &dummy2;
    ListNode *p = l1;
    while (p != nullptr)
    {
        if (p->val < x)
        {
            cur1->next = p;
            cur1 = cur1->next;
        }
        else
        {
            cur2->next = p;
            cur2 = cur2->next;
        }
        ListNode *temp = p->next;
        p->next = nullptr;
        p = temp;
    }
    cur1->next = dummy2.next;
    return dummy1.next;
}