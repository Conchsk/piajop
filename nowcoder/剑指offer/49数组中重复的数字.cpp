#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool duplicate(int numbers[], int length, int *duplication)
    {
        vector<bool> temp(length, false);
        for (int i = 0; i < length; ++i)
        {
            if (temp[numbers[i]])
            {
                *duplication = numbers[i];
                return true;
            }
            temp[numbers[i]] = true;
        }
        return false;
    }
};