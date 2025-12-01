// K 个一组反转链表

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

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == nullptr)
        return nullptr;
    // 区间 [a, b) 包含 k 个待反转元素
    ListNode *a, *b;
    a = b = head;
    for (int i = 0; i < k; i++)
    {
        // 不足 k 个，不需要反转了
        if (b == nullptr)
            return head;
        b = b->next;
    }
    // 反转前 k 个元素
    ListNode *newHead = reverseN(a, k);
    // 此时 b 指向下一组待反转的头结点
    // 递归反转后续链表并连接起来
    a->next = reverseKGroup(b, k);
    return newHead;
}

// 上文实现的反转前 N 个节点的函数
ListNode *reverseN(ListNode *head, int n)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *pre, *cur, *nxt;
    pre = nullptr;
    cur = head;
    nxt = head->next;
    while (n > 0)
    {
        cur->next = pre;
        pre = cur;
        cur = nxt;
        if (nxt != nullptr)
        {
            nxt = nxt->next;
        }
        n--;
    }
    head->next = cur;
    return pre;
}
