#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if (n < 1)
            return 0;
        return helper(n, ceil(log10(n + 1)));
    }

    int helper(int n, int width)
    {
        if (n == 0)
            return 0;
        int mod = pow(10, width - 1);
        int first = n / mod;
        int count = first * (width - 1) * mod / 10;
        if (first == 1)
            count += n % mod + 1;
        else
            count += mod;
        return count + helper(n % mod, width - 1);
    }
};