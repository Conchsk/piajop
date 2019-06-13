#include <iostream>
using namespace std;

class Solution
{
public:
    int Fibonacci(int n)
    {
        int a = 0, b = 1;
        while (n--)
        {
            int t = b;
            b = a + b;
            a = t;
        }
        return a;
    }
};
