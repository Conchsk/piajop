#include <iostream>
using namespace std;

class Solution
{
public:
    int rectCover(int number)
    {
        if (number == 0)
            return 0;
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
