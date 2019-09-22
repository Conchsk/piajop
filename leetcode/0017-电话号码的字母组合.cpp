// link https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> keyboard{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void helper(string &digits, vector<string> &ret, string &buffer)
    {
        if (digits.length() == buffer.length())
            ret.push_back(buffer);
        else
        {
            int index = digits[buffer.length()] - '0';
            for (auto it = keyboard[index].begin(); it != keyboard[index].end(); ++it)
            {
                buffer.push_back(*it);
                helper(digits, ret, buffer);
                buffer.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> ret;
        string buffer;
        if (digits.length() == 0)
            return ret;
        else
        {
            helper(digits, ret, buffer);
            return ret;
        }
    }
};
