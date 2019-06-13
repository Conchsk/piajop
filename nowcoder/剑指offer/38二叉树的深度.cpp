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
    int TreeDepth(TreeNode *pRoot)
    {
        return pRoot ? helper(pRoot, 1), depth : 0;
    }

    int depth = 0;

    void helper(TreeNode *p, int level)
    {
        if (depth < level)
            depth = level;
        if (p->left)
            helper(p->left, level + 1);
        if (p->right)
            helper(p->right, level + 1);
    }
};