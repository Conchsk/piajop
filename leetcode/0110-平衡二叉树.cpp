// link https://leetcode-cn.com/problems/balanced-binary-tree/
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
    bool helper(TreeNode *p, int *height)
    {
        if (!p)
            return true;
        int leftHeight = 0;
        int rightHeight = 0;
        if (!helper(p->left, &leftHeight) || !helper(p->right, &rightHeight) || abs(leftHeight - rightHeight) > 1)
            return false;
        else
        {
            if (height)
                *height = max(leftHeight, rightHeight) + 1;
            return true;
        }
    }

    bool isBalanced(TreeNode *root)
    {
        return helper(root, NULL);
    }
};
