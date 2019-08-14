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
    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if (!pRoot1 || !pRoot2)
            return false;
        if (pRoot1->val == pRoot2->val)
            return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2) || sameStructure(pRoot1, pRoot2);
        else
            return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }

    bool sameStructure(TreeNode *p1, TreeNode *p2)
    {
        if (!p2)
            return true;
        if (!p1)
            return false;
        if (p1->val != p2->val)
            return false;
        else
            return sameStructure(p1->left, p2->left) && sameStructure(p1->right, p2->right);
    }
};
