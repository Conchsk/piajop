// link https://leetcode-cn.com/problems/generate-parentheses/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    void helper(int n, vector<string> &ret, string &buffer, int left, int right)
    {
        if (buffer.length() == 2 * n)
            ret.push_back(buffer);
        else
        {
            if (left < n)
            {
                buffer.push_back('(');
                helper(n, ret, buffer, left + 1, right);
                buffer.pop_back();
            }
            if (right < n && right < left)
            {
                buffer.push_back(')');
                helper(n, ret, buffer, left, right + 1);
                buffer.pop_back();
            }
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> ret;
        string buffer;
        if (n == 0)
            return ret;
        else
        {
            helper(n, ret, buffer, 0, 0);
            return ret;
        }
    }
};
