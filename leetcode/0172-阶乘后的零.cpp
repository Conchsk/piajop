// link https://leetcode-cn.com/problems/factorial-trailing-zeroes/
#include <iostream>
using namespace std;

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int ret = 0;
        for (long long factor = 5; factor <= n; factor *= 5)
            ret += n / factor;
        return ret;
    }
};
