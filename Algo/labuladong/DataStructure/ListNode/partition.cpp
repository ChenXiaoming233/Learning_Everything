// 单链表的分解
// #安全摘链操作：从原链表中破坏性取出一个节点，把它的 next 指针断开，让它成为一个独立节点，然后再接到新的链表中。

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

ListNode *partition(ListNode *head, int x)
{
    ListNode dummy1(0);
    ListNode dummy2(0);
    ListNode *current1 = &dummy1;
    ListNode *current2 = &dummy2;
    ListNode *p = head;
    while (p != nullptr)
    {
        if (p->val < x)
        {
            current1->next = p;
            current1 = current1->next;
        }
        else
        {
            current2->next = p;
            current2 = current2->next;
        }
        // ! 注意 安全摘链操作：从原链表中破坏性地取出一个节点，把它的 next 指针断开，让它成为一个独立节点，然后再接到新的链表中。
        ListNode *temp = p->next;
        p->next = nullptr;
        // p 前进到下一节点
        p = temp;
    }
    current1->next = dummy2.next;
    return dummy1.next;
}
