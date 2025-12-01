// 反转前 n 个节点

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

ListNode* reverseN(ListNode* head, int n) {
    ListNode *pre, *cur;
    pre = nullptr;
    cur = head;
    while(n-- and cur != nullptr){
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    head->next = cur;
    return pre;
}