// link https://leetcode-cn.com/problems/powx-n/
#include <iostream>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n < 0)
        {
            if (n != (int)0x80000000)
                return 1.0 / myPow(x, -n);
            else
                return 1.0 / (myPow(x, -(n + 1)) * x);
        }
        else
        {
            double ret = 1.0;
            while (n)
            {
                if (n & 1)
                    ret *= x;
                x *= x;
                n >>= 1;
            }
            return ret;
        }
    }
};
