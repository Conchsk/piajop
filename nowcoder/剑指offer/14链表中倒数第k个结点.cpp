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
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k)
    {
        ListNode *p = pListHead;
        int len = 0;
        while (p)
        {
            p = p->next;
            len++;
        }
        if (len < k)
            return NULL;
        while (len - k)
        {
            p = p->next;
            len--;
        }
        return p;
    }
};
