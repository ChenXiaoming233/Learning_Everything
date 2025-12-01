// 反转链表的一部分

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

ListNode *reverseBetween(ListNode *head, int m, int n)
{
    if (head == nullptr or head->next == nullptr or m == n) // 链表为空或只有一个节点或区间长度为0直接返回
    {
        return head;
    }

    // ! 注意 使用头插法需要使用虚拟头节点，防止 m = 1 时无法处理
    ListNode dummy(0);
    dummy.next = head;
    ListNode *pre = &dummy;

    // ! 注意 要将 pre 移动到 m - 1 的位置，循环区间 int i = 0; i < m - 1;
    for (int i = 0; i < m - 1; i++)
    {
        pre = pre->next;
    }

    ListNode *start = pre->next; // start 为区间的第一个节点，最终会变成区间的最后一个节点
    ListNode *cur = start->next; // cur 为要被头插的节点

    // ! 注意 头插法保持链表结构完整，不会让区间头指向区间外，与三指针法不同
    // ! 注意 循环区间 i = 0; i < n - m;
    for (int i = 0; i < n - m; i++)
    {
        // 1. 从链表中取出 cur, start 的下一个节点跳过 cur 直接指向 cur 的下一个节点
        start->next = cur->next;

        // 2. 将 cur 插入 pre 后
        cur->next = pre->next;
        pre->next = cur;

        // 3. 更新 cur 到下一个将被移动的节点
        cur = start->next;
    }

    return dummy.next;
}
