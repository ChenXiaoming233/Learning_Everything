// 单链表的倒数第 k 个节点

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

ListNode* findFromEnd(ListNode* head, int k) {
    ListNode* p1 = head;
    // p1 先走 k 步
    for (int i = 0; i < k; i++) {
        p1 = p1 -> next;
    }
    ListNode* p2 = head;
    // p1 和 p2 同时走 n - k 步
    while (p1 != nullptr) {
        p2 = p2 -> next;
        p1 = p1 -> next;
    }
    // p2 现在指向第 n - k + 1 个节点，即倒数第 k 个节点
    return p2;
}