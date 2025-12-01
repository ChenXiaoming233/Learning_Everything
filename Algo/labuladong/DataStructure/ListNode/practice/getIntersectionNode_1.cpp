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
    ListNode* p1 = headA;
    ListNode* p2 = headB;
    while(p1 != p2){
        p1 = (p1 == nullptr) ? headB : p1->next;
        p2 = (p2 == nullptr) ? headA : p2->next;
    }
    return p1;
}
