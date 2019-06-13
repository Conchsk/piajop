#include <iostream>
using namespace std;

class Solution
{
public:
    int jumpFloor(int number)
    {
        int a = 1, b = 1;
        while (number--)
        {
            int t = b;
            b = a + b;
            a = t;
        }
        return a;
    }
};
