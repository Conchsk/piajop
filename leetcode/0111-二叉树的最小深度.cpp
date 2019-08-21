// link https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
#include <iostream>
#include <queue>
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
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int ret = 1;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            TreeNode *p = q.front();
            q.pop();
            if (!p)
            {
                if (!q.empty())
                    q.push(p);
                ++ret;
                continue;
            }
            if (!p->left && !p->right)
                break;
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
        return ret;
    }
};
