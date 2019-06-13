#include <iostream>
using namespace std;

class Solution
{
public:
    int LastRemaining_Solution(int n, int m)
    {
        bool *temp = new bool[n];
        int remain = n;
        int cursor = 0;
        while (remain > 1)
        {
            for (int j = 0; j < m; ++j)
            {
                cursor = (cursor + 1) % n;
                if (temp[cursor])
                    cursor = (cursor + 1) % n;
            }
            temp[cursor] = true;
            --remain;
        }
        for (int i = 0; i < n; ++i)
            if (!temp[i])
                return i;
        return -1;
    }
};