/**
 * 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
    {
        int temp = 0;
        for (auto it = data.begin(); it != data.end(); ++it)
            temp ^= *it;
        int lowbit = temp & -temp;
        *num1 = *num2 = 0;
        for (auto it = data.begin(); it != data.end(); ++it)
            if (*it & lowbit)
                *num1 ^= *it;
            else
                *num2 ^= *it;
    }
};