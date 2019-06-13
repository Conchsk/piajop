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
    ListNode *ReverseList(ListNode *pHead)
    {
        ListNode *cur, *prev, *post;
        cur = pHead;
        prev = NULL;
        while (cur)
        {
            post = cur->next;
            cur->next = prev;
            prev = cur;
            cur = post;
        }
        return prev;
    }
};
