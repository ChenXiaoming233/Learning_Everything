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

ListNode *findFromEnd(ListNode *head, int x)
{
    ListNode *fast = head;
    ListNode *slow = head;
    if (head == nullptr) // 检查空指针！
        return nullptr;

    for (int i = 0; i < x; i++)
    {
        if (fast == nullptr) // 检查链表长度是否长于 x !
            return nullptr;
        fast = fast->next;
    }
    while (fast != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}