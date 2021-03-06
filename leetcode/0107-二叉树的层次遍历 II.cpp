// link https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/
#include <iostream>
#include <vector>
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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (!root)
            return vector<vector<int>>();
        vector<vector<int>> ret;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<int> temp;
        while (!q.empty())
        {
            TreeNode *p = q.front();
            q.pop();
            if (!p)
            {
                if (!q.empty())
                    q.push(p);
                ret.insert(ret.begin(), temp);
                temp.clear();
                continue;
            }
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
            temp.push_back(p->val);
        }
        return ret;
    }
};
