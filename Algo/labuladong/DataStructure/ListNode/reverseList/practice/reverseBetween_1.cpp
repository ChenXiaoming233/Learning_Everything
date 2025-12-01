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

ListNode* reverseBetween (ListNode *head, int m, int n){
    if(m == n){
        return head;
    }

    ListNode dummy(0);
    dummy.next = head;
    ListNode* pre = &dummy;
    
    for(int i = 0; i < m - 1; i++){
        pre = pre->next;
    }
    
    ListNode* start = pre->next;
    ListNode* cur = start->next;

    for(int i = 0; i < n - m; i++){
        ListNode* next = cur->next;
        start->next = cur->next;
        cur->next = pre->next;
        pre->next = cur;
        cur = start->next;
    }
    return dummy.next;
}