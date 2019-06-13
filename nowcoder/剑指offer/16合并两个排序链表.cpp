#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

class Solution
{
public:
    ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
    {
        ListNode newHead(-1);
        ListNode *p = pHead1;
        ListNode *q = pHead2;
        ListNode *t = &newHead;
        while (p && q)
        {
            if (p->val < q->val)
            {
                t->next = p;
                p = p->next;
            }
            else
            {
                t->next = q;
                q = q->next;
            }
            t = t->next;
        }
        if (!q)
            t->next = p;
        if (!p)
            t->next = q;
        return newHead.next;
    }
};
