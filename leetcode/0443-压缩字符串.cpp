// link https://leetcode-cn.com/problems/string-compression/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int ret = chars.size();
        int tmp;
        for (int i = 0; i < chars.size() - 1; ++i)
        {
            tmp = 1;
            while (chars[i] == chars[i + 1])
            {
                ++tmp;
                ++i;
            }
            if (tmp > 1)
                ret -= (tmp - (int)ceil(log10(tmp)));
        }
        return ret;
    }
};
