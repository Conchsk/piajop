#include <iostream>
#include <vector>
#include <algorithm>
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
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a.size() > b.size();
    }

    vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
    {
        vector<vector<int>> ret;
        vector<int> path;
        if (root)
            helper(root, expectNumber, path, 0, ret);
        sort(ret.begin(), ret.end(), compare);
        return ret;
    }

    void helper(TreeNode *root, int expectNumber, vector<int> &path, int sum, vector<vector<int>> &ret)
    {
        path.push_back(root->val);
        if (!root->left && !root->right)
        {
            if (sum + root->val == expectNumber)
            {
                vector<int> temp(path);
                ret.push_back(temp);
            }
        }
        if (root->left)
            helper(root->left, expectNumber, path, sum + root->val, ret);
        if (root->right)
            helper(root->right, expectNumber, path, sum + root->val, ret);
        path.pop_back();
    }
};
