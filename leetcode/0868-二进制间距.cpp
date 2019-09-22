// link https://leetcode-cn.com/problems/binary-gap/
#include <iostream>
using namespace std;

class Solution
{
public:
    int binaryGap(int N)
    {
        int maxGap = 0;
        int tmpGap = 0;
        while (N)
        {
            if (N & 1)
            {
                if (maxGap < tmpGap)
                    maxGap = tmpGap;
                tmpGap = 1;
            }
            else if (tmpGap)
                ++tmpGap;
            N >>= 1;
        }
        return maxGap;
    }
};
