#include <iostream>
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
    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        if (!pRootOfTree)
            return pRootOfTree;
        helper(pRootOfTree);
        while (pRootOfTree->left)
            pRootOfTree = pRootOfTree->left;
        return pRootOfTree;
    }

    TreeNode *pre = NULL;

    void helper(TreeNode *cur)
    {
        if (cur->left)
            helper(cur->left);
        cur->left = pre;
        if (pre)
            pre->right = cur;
        pre = cur;
        if (cur->right)
            helper(cur->right);
    }
};