#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    double Power(double base, int exponent)
    {
        if (exponent < 0)
        {
            exponent = -exponent;
            base = 1 / base;
        }
        double ret = 1.0;
        while (exponent)
        {
            if (exponent & 1)
                ret *= base;
            base *= base;
            exponent >>= 1;
        }
        return ret;
    }
};
