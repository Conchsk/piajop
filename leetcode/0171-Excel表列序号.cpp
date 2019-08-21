// link https://leetcode-cn.com/problems/excel-sheet-column-number/
#include <iostream>
using namespace std;

class Solution
{
public:
    int titleToNumber(string s)
    {
        int ret = 0;
        for (auto it = s.begin(); it != s.end(); ++it)
        {
            ret = ret * 26 + 1;
            ret += *it - 'A';
        }
        return ret;
    }
};
