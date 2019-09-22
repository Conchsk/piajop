// link https://leetcode-cn.com/problems/subtree-of-another-tree/
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool isSameTree(TreeNode *s, TreeNode *t)
    {
        if (!s && !t)
            return true;
        else if (s && t)
        {
            if (s->val == t->val)
                return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
            else
                return false;
        }
        else
            return false;
    }

    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (!s && !t)
            return true;
        else if (s && t)
        {
            bool flag = s->val == t->val ? isSameTree(s, t) : false;
            flag = flag || isSubtree(s->left, t) || isSubtree(s->right, t);
            return flag;
        }
        else
            return false;
    }
};
