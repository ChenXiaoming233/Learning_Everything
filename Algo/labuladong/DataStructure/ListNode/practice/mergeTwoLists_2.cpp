#include <bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x){
        val = x;
        next = nullptr;
    }
};

ListNode* mergeTwoList(ListNode *l1, ListNode *l2){
    ListNode dummy(0);
    ListNode *current = &dummy;
    ListNode *p1 = l1, *p2 = l2;
    while(p1 != nullptr && p2 != nullptr){
        if(p1->val < p2->val){
            current->next = p1;
            p1 = p1->next;
        }
        else{
            current->next = p2;
            p2 = p2->next;
        }
        current = current->next;
    }
    if(p1 == nullptr){
        current->next = p2;
    }
    else{
        current->next = p1;
    }
    return dummy.next;
}