#include <iostream>
using namespace std;

class Solution
{
public:
    int Sum_Solution(int n)
    {
        int ret = n;
        ret && (ret += Sum_Solution(n - 1));
        return ret;
    }
};