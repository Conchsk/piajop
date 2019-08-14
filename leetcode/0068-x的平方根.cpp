// link https://leetcode-cn.com/problems/sqrtx/submissions/
#include <cmath>

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;
        double z = 1.0;
        while (abs(z - (z * z + x) / (2 * z)) > 1e-8)
            z = (z * z + x) / (2 * z); // newton method
        return int(floor(z));
    }
};