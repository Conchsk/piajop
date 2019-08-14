#include <iostream>
using namespace std;

class Solution
{
public:
    int jumpFloorII(int number)
    {
        int ret = 1;
        while (--number)
            ret *= 2;
        return ret;
    }
};
