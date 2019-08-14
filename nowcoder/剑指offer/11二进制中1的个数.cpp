#include <iostream>
using namespace std;

class Solution
{
public:
    int NumberOf1(int n)
    {
        int i, ret = 0;
        for (i = 0; i < 32; ++i)
        {
            ret += n & 1;
            n >>= 1;
        }
        return ret;
    }
};
