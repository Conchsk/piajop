#include <iostream>
#include <cstring>
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
    bool helper(ListNode *&head)
    {
        bool ret = false;

        ListNode *buffer[1001];
        int length = 0;
        for (ListNode *p = head; p != NULL; p = p->next)
            buffer[length++] = p;
        buffer[length] = NULL;

        for (int i = 0; i < length; ++i)
        {
            int count = 0;
            for (int j = i; j < length; ++j)
            {
                count += buffer[j]->val;
                if (count == 0)
                {
                    ret = true;
                    if (i == 0)
                    {
                        while (head != buffer[j + 1])
                        {
                            // delete head;
                            head = head->next;
                        }
                    }
                    else
                    {
                        ListNode *temp = buffer[i];
                        while (temp != buffer[j + 1])
                        {
                            // delete temp;
                            temp = temp->next;
                        }
                        buffer[i - 1]->next = buffer[j + 1];
                    }
                    i = j + 1;
                    break;
                }
            }
        }
        return ret;
    }

    ListNode *removeZeroSumSublists(ListNode *head)
    {
        while (helper(head))
            ;
        return head;
    }
};

int main(void)
{
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(-3);
    ListNode l5(4);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    auto head = Solution().removeZeroSumSublists(&l1);
    while (head)
    {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}
