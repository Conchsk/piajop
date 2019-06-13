#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

class Solution
{
public:
    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        if (!pRoot)
            return true;
        return helper(pRoot) == -1 ? false : true;
    }

    int helper(TreeNode *p)
    {
        if (!p)
            return 0;

        int left = helper(p->left);
        if (left == -1)
            return -1;
        int right = helper(p->right);
        if (right == -1)
            return -1;

        if (abs(left - right) > 1)
            return -1;
        else
            return max(left, right) + 1;
    }
};