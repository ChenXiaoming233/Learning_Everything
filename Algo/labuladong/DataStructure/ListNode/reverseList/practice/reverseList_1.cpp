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

ListNode* reverseList (ListNode* head){
    ListNode* pre, *cur;
    pre = nullptr;
    cur = head;
    while(cur != nullptr){
        ListNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}