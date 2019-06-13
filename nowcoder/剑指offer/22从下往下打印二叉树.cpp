#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> PrintFromTopToBottom(TreeNode *root)
    {
        vector<int> ret;
        if (!root)
            return ret;
        queue<TreeNode *> temp;
        temp.push(root);
        while (!temp.empty())
        {
            ret.push_back(temp.front()->val);
            if (temp.front()->left != NULL)
                temp.push(temp.front()->left);
            if (temp.front()->right != NULL)
                temp.push(temp.front()->right);
            temp.pop();
        }
        return ret;
    }
};
