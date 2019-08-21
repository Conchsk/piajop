// link https://leetcode-cn.com/problems/palindrome-number/
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        else
        {
            unsigned int ox = x; // original x
            unsigned int rx = 0; // reversed x
            while (x)
            {
                rx *= 10;
                rx += x % 10;
                x /= 10;
            }
            return ox == rx;
        }
    }
};
