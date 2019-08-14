// link https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
#include <iostream>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *p, *q, *r;
        p = head;
        q = p->next;
        while (q)
        {
            r = q->next;
            if (p->val == q->val)
            {
                p->next = r;
                delete q;
            }
            else
                p = q;
            q = r;
        }
        return head;
    }
};