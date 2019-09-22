// link https://leetcode-cn.com/problems/implement-rand10-using-rand7/
#include <iostream>
using namespace std;

// The rand7() API is already defined for you.
int rand7();
// @return a random integer in the range 1 to 7

class Solution
{
public:
    int rand10()
    {
        int first = rand7();
        if (first < 6)
        {
            int second = 0;
            while (second < 6)
                second = rand7();
            if (second == 6)
                return first;
            else
                return first + 5;
        }
        else
        {
            int second = 6;
            while (second > 5)
                second = rand7();
            if (first == 6)
                return second;
            else
                return second + 5;
        }
    }
};
