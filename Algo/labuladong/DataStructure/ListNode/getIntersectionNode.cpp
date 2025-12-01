// 两个链表是否相交

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

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    // p1 指向 A 链表头结点，p2 指向 B 链表头结点
    ListNode* p1 = headA;
    ListNode* p2 = headB;
    while (p1 != p2) {
        // p1 走一步，如果走到 A 链表末尾，转到 B 链表
        p1 = (p1 == nullptr) ? headB : p1->next;
        // p2 走一步，如果走到 B 链表末尾，转到 A 链表
        p2 = (p2 == nullptr) ? headA : p2->next;
    }
    return p1;
}
