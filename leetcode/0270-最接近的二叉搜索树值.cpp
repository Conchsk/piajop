// link https://leetcode-cn.com/problems/closest-binary-search-tree-value/
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
    int closestValue(TreeNode *root, double target)
    {
        TreeNode *p = root;
        double distance = 1e11;
        int ret = 0;
        while (p)
        {
            if (distance > abs(target - p->val))
            {
                distance = abs(target - p->val);
                ret = p->val;
            }
            if (p->val > target)
                p = p->left;
            else if (p->val == target)
                break;
            else
                p = p->right;
        }
        return ret;
    }
};
