// link: https://leetcode-cn.com/problems/zigzag-conversion/
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        string ret;
        for (int i = 0; i < numRows; ++i)
        {
            bool flag = true;
            int j = i;
            while (j < s.length())
            {
                if ((i == 0 && !flag) || (i == numRows - 1 && flag))
                {
                    flag = !flag;
                    continue;
                }
                ret.push_back(s[j]);
                if (flag)
                    j += 2 * (numRows - i - 1);
                else
                    j += 2 * i;
                flag = !flag;
            }
        }
        return ret;
    }
};
