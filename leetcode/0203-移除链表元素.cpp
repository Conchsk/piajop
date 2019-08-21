// link https://leetcode-cn.com/problems/remove-linked-list-elements/

#include <iostream>
using namespace std;

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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode newHead(0);
        newHead.next = head;
        ListNode *p, *q, *r;
        p = &newHead;
        q = p->next;
        while (q)
        {
            r = q->next;
            if (q->val == val)
            {
                p->next = r;
                delete q;
            }
            else
                p = q;
            q = r;
        }
        return newHead.next;
    }
};
