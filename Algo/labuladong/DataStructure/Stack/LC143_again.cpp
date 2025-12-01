// LC143 - 重排链表

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

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        std::stack<ListNode *> stk;
        // 先把所有节点装进栈里，得到倒序结果
        ListNode *p = head;
        while (p != nullptr)
        {
            stk.push(p);
            p = p->next;
        }

        p = head;
        while (!stk.empty())
        {
            // 链表尾部的节点
            ListNode *lastNode = stk.top();
            stk.pop();
            ListNode *next = p->next; // 暂存原始链表中 p 的下一个节点
            if (lastNode == next || lastNode->next == next)
            {
                // 结束条件，链表节点数为奇数或偶数时均适用
                lastNode->next = nullptr;
                break;
            }
            p->next = lastNode; // 修改 p 的下一个节点为倒序弹出的节点
            lastNode->next = next; // 令倒序弹出的节点的下一个节点为原始链表中 p 的下一个节点
            p = next; // p 向后移动至原始链表中 p 的下一个节点
        }
    }
};