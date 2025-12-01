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

ListNode *reverseN(ListNode *head, int n)
{
    if (head == nullptr or head->next == nullptr or n == 0 or n == 1) // 链表为空或只有一个节点直接返回
    {
        return head;
    }

    ListNode *pre, *cur;
    pre = nullptr;
    cur = head;

    // ！注意 防止空指针
    while (n-- and cur != nullptr) 
    {
        ListNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    // ! 注意 不要忘记合并
    head->next = cur; // 此时的 cur 是第 n + 1 个节点，head 是反转后的尾结点

    // 此时的 pre 是反转后的头结点
    return pre;
}