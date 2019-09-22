// link https://leetcode-cn.com/problems/can-place-flowers/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        for (int i = 0; i < flowerbed.size(); ++i)
        {
            int field = flowerbed[i];
            if (i > 0)
                field += flowerbed[i - 1];
            if (i < flowerbed.size() - 1)
                field += flowerbed[i + 1];
            if (field == 0)
            {
                if (--n <= 0)
                    break;
                ++i;
            }
        }
        return n <= 0;
    }
};
