// link https://leetcode-cn.com/problems/add-digits/
#include <iostream>
using namespace std;

class Solution
{
public:
    int addDigits(int num)
    {
        if (num == 0)
            return 0;
        else if (num % 9 == 0)
            return 9;
        else
            return num % 9;
    }
};
