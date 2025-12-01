// 反转整个链表
// #空指针判断：一旦出现类似 nxt.next 这种操作，就要条件反射地想到，先判断 nxt 是否为 null，否则容易出现空指针异常。

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

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr or head->next == nullptr) // 链表为空或只有一个节点直接返回
    {
        return head;
    }

    ListNode *pre, *cur;
    pre = nullptr;
    cur = head;
    
    // 普通反转 三指针法
    while (cur != nullptr)
    {
        // 防止 head = nullptr 导致爆炸
        ListNode *nxt = cur->next; // 保存下一节点
        cur->next = pre;           // 扭转指针
        pre = cur;                 // pre 前进一步
        cur = nxt;                 // cur 前进一步
    }
    
    // 返回反转后的头结点
    return pre; // 反转结束时 nxt 与 cur 都是 nullptr
}
