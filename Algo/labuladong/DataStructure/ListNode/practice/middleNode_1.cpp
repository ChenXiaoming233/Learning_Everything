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

ListNode *middleNode(ListNode *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != nullptr and fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}